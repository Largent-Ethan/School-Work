import sqlite3
conn = sqlite3.connect('database.db')
cursor = conn.cursor()
cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
tables = cursor.fetchall()
for table in tables:
    table_name = table[0]
    print(f"\nTable: {table_name}")

    cursor.execute(f"PRAGMA table_info({table_name});")
    columns_info = cursor.fetchall()
    column_names = [column[1] for column in columns_info]
    print("Columns:", column_names)

    cursor.execute(f'SELECT * FROM {table_name}')
    while True:
      rows = cursor.fetchmany(1000) 

      if not rows:
         break
      for row in rows:   
         if row[0] == 457:
            print(row)
         if row[0] == 882:
            print(row)

conn.close()
