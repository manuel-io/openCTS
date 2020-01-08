import glob, json
from contextlib import closing
from config import *

db = get_db()

for path in glob.glob('./share/assets/autobuses.js'):
    with open(path) as fd:
        for obj in json.loads(fd.read()):
            with closing(db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
                try:
                    with open('./share/assets/autobuses/%s' % obj['a'], 'rb') as a:
                        with open('./share/assets/autobuses/%s' % obj['b'], 'rb') as b:
                            with open('./share/assets/autobuses/%s' % obj['c'], 'rb') as c:
                                with open('./share/assets/autobuses/%s' % obj['d'], 'rb') as d:
                                    print('Autobus', obj['title'])

                                    cursor.execute("""
                                        INSERT INTO opencts_autobuses
                                        (title, seats, standing, a, b, c, d)
                                        VALUES (%s, %s, %s, %s, %s, %s, %s)
                                            """, [ obj['title']
                                                 , obj['seats'] 
                                                 , obj['standing'] 
                                                 , psycopg2.Binary(a.read())
                                                 , psycopg2.Binary(b.read())
                                                 , psycopg2.Binary(c.read())
                                                 , psycopg2.Binary(d.read())
                                                 ])
            
                                    db.commit()

                except Warning:
                    db.rollback()

for path in glob.glob('./share/assets/streets.js'):
    with open(path) as fd:
        for obj in json.loads(fd.read()):
            with closing(db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
                try:
                    with open('./share/assets/streets/%s' % obj['tile'], 'rb') as tile:
                        print('Street', obj['title'])
                        cursor.execute("""
                            INSERT INTO opencts_streets
                            (title, tile, paths)
                            VALUES (%s, %s, %s)
                                """, [ obj['title']
                                     , psycopg2.Binary(tile.read())
                                     , json.dumps(obj['paths'])
                                     ])

                        db.commit()

                except Warning:
                    db.rollback()
