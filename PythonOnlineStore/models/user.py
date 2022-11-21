from .mongodb import conn_mongodb
from datetime import datetime
from bson import ObjectId
from flask_bcrypt import generate_password_hash, check_password_hash

class User():
    @staticmethod
    def insert_one(user):
        db = conn_mongodb()
        password_hash = generate_password_hash(user['password'])
        db.users.insert_one({
            'email': user['email'],
            'password': password_hash,
            'created_at': int(datetime.now().timestamp()),
            'updated_at': int(datetime.now().timestamp())
        })
    
    @staticmethod
    def check_email(email):
        db = conn_mongodb()
        user = db.users.find_one({'email': email})
    
        return True if user else False

    @staticmethod
    def sign_in(login_data):
        db = conn_mongodb()
        user = db.users.find_one({'email': login_data['email']})

        if not user:
            return False
        
        if not check_password_hash(user['password'], login_data['password']):
            return False

        return user
