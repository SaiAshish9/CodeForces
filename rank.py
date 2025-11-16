# 🚀 Python script for fetching your All India Rank (AIR) in a Codeforces contest

import requests
import json

contest_id = "2164" 
handle = "saiashish9"

url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=3500"
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

handles = ";".join(map(lambda x: x["handle"], rows))

def fetch_user_info(handles):
    result = []
    for i in range(0, len(handles), 500):  # batches of 500
        batch = handles[i:i+500]
        url = "https://codeforces.com/api/user.info"
        resp = requests.get(url, params={"handles": ";".join(batch)}).json()
        if resp["status"] != "OK":
            raise Exception("API error")
        result.extend(resp["result"])
    return result

user_data = fetch_user_info([row["handle"] for row in rows])

country = list(
    map(lambda x: {"handle": x["handle"], "country": x.get("country", "Unknown")}, user_data)
)

for row in rows:
    for c in country:
        if row["handle"] == c["handle"] and c["country"] == "India" and c["country"] != "Unknown":
            row["country"] = c["country"]
            break
        
res= []
for row in rows:
    if "country" in row and row["country"] == "India":
        res.append(row)
        
seen = set()
ans = []

for entry in res:
    if entry["rank"] not in seen:
        ans.append(entry)
        seen.add(entry["rank"])

with open("rows.json", "w", encoding="utf-8") as f:
    json.dump(ans, f, ensure_ascii=False, indent=2)

country = list(filter(lambda x: x["country"] == "India", country))

print(f"AIR of handle {country[-1]["handle"]} : {len(ans)}")

# python3 -m venv codeforces   
# source codeforces/bin/activate
# pip install requests
# python rank.py        
# deactivate