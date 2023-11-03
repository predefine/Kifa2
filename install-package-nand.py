import json
import io
import sys
import lief

dst = sys.argv[2]
src = sys.argv[1]

meta = None

with open(f'{src}/meta.json') as f:
    meta = json.load(f)

print(meta)

# TODO