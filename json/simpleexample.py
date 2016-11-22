import json

sampleData = ['foo',
			{
				'bar': ('baz', None, 1.0, 2)
			}
			]

print("Data to serialize: ")
print(sampleData)

serialized = json.dumps(sampleData, sort_keys=True, indent=4)

print("JSON:")
print(serialized)

dataLoaded = json.loads(serialized)

print("Loaded data:")
print(dataLoaded)
