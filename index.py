import psycopg2, psycopg2.extras, datetime, json, io
from flask import Flask, render_template, request, g, send_file
from config import get_db, SECRET_KEY
from contextlib import closing
app = Flask(__name__)

@app.before_request
def before_request():
    g.db = get_db();

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/data')
def data():
    data = { 'streets': []
           , 'autobuses': []
           }

    with closing(g.db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
        try:
            cursor.execute("""
                SELECT title,uid,paths::json FROM opencts_streets
            """)

            for street in cursor.fetchall():
                data['streets'].append(dict(street))
        
        except:
            g.db.rollback()

    with closing(g.db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
        try:
            cursor.execute("""
                SELECT title,uid,seats,standing FROM opencts_autobuses
            """)

            for autobus in cursor.fetchall():
                data['autobuses'].append(dict(autobus))
        
        except:
            g.db.rollback()

    return json.dumps(data)

@app.route('/streets/<uid>')
def streets(uid):
    with closing(g.db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
        try:
            cursor.execute("""
                SELECT tile FROM opencts_streets
                WHERE uid = %s LIMIT 1
            """, [uid])

            data = cursor.fetchone()
            return send_file( io.BytesIO(data["tile"])
                            , mimetype = 'image/png'
                            , as_attachment = False
                            )
        
        except Warning:
            g.db.rollback()

    return ""

@app.route('/autobuses/<uid>/<view>')
def autobuses(uid, view):
    with closing(g.db.cursor(cursor_factory = psycopg2.extras.DictCursor)) as cursor:
        try:
            cursor.execute("""
                SELECT a,b,c,d FROM opencts_autobuses
                WHERE uid = %s LIMIT 1
            """, [uid])

            data = cursor.fetchone()
            return send_file( io.BytesIO(data[view])
                            , mimetype = 'image/png'
                            , as_attachment = False
                            )
        
        except Warning:
            g.db.rollback()

    return ""

if __name__ == '__main__':
    app.run(host = '127.0.0.1')
