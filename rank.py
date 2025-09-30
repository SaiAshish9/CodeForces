import requests
import json

contest_id = 2149 
handle = ""

url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=700"
resp = requests.get(url).json()

if resp["status"] != "OK":
    raise Exception("API error")

rows = resp["result"]["rows"]

rows = list(
    map(lambda x: {"rank": x["rank"], "handle": x["party"]["members"][0]["handle"]}, rows)
)

index = next(
    (i for i, row in enumerate(rows) 
     if row["handle"].lower() == handle.lower()), 
    None
)

rows = rows[:index+1]

print(f"Total participants: {len(rows)}")

handles = ";".join(map(lambda x: x["handle"], rows))

api = f"https://codeforces.com/api/user.info?handles={handles}"
resp = requests.get(api).json()
country = list(
    map(lambda x: {"handle": x["handle"], "country": x.get("country", "Unknown")}, resp["result"])
)

for row in rows:
    for c in country:
        if row["handle"] == c["handle"] and c["country"] != "Unknown":
            row["country"] = c["country"]
            break
        
with open("rows.json", "w", encoding="utf-8") as f:
    json.dump(rows, f, ensure_ascii=False, indent=2)

country = list(filter(lambda x: x["country"] == "India", country))

print(f"Total Indian participants: {len(country)}")
print(country[-1]["handle"])

# python3 -m venv codeforces   
# source codeforces/bin/activate
# pip install requests
# python rank.py        
# deactivate