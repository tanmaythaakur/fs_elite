versions = input().split()

maxLen = 0
# print("Original: ", versions)

for v in versions:
    maxLen = max(maxLen, len(v))

# print(maxLen)

versionModified = []

for v in versions:
    while len(v) < maxLen:
        v += "-0"
    versionModified.append(v)

# print("Modified: ", versionModified)

maxVersion = versionModified[0]
idx = 0

for i in range(1, len(versionModified)):

    if maxVersion == versionModified[i]:
        # print("Reached")
        if len(versions[i]) < len(versions[idx]):
            # print("HERE")
            maxVersion = versionModified[i]
            idx = i
    elif maxVersion < versionModified[i]:
        maxVersion = versionModified[i]
        idx = i

# print(maxVersion)
print(versions[idx])


