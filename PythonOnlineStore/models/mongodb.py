import pymongo

MONGO_URI = "mongodb+srv://root:root1234@cluster0.clbzvk0.mongodb.net/?retryWrites=true&w=majority"
MONGO_CONN = pymongo.MongoClient(MONGO_URI)

def conn_mongodb():
    db = MONGO_CONN.online_store

    # DB 연결 Test
    # test_connection = db.test_connection.insert_one({'test': 'test'})
    
    return db

# DB 연결 Test
# conn_mongodb()
