import pymssql

conn = pymssql.connect("192.168.56.20", "mpsadmin", "mpsadmin", "mps_database")
cursor = conn.cursor()
cursor.execute("""
SELECT * FROM test2
""")

row = cursor.fetchone()
while row:
    print("ID=%d, Name=%s, Lastname=%s" % (row[0], row[1], row[2]))
    row = cursor.fetchone()

conn.close()