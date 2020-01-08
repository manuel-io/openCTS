import psycopg2, psycopg2.extras, os
from datetime import datetime
from dateutil import tz

SECRET_KEY = os.urandom(32)

def get_db():
    db = psycopg2.connect( host = os.environ["OPENCTS_HOST"]
                             if "OPENCTS_HOST" in os.environ else "localhost"
                           , dbname = os.environ["OPENCTS_DBNAME"]
                             if "OPENCTS_DBNAME" in os.environ else "opencts"
                           , user = os.environ["OPENCTS_USR"]
                             if "OPENCTS_USR" in os.environ else "opencts"
                           , password = os.environ["OPENCTS_PWD"]
                             if "OPENCTS_PWD" in os.environ else None
                           )
    return db

utczone = tz.gettz('UTC')
dbzone = tz.gettz('UTC')
zone = tz.gettz('Europa/Berlin')
today = datetime.utcnow().replace(tzinfo = utczone).astimezone(zone)
