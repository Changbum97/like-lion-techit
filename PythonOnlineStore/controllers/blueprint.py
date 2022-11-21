# API 들을 보기좋게 구분해놓기 위해 blueprint 사용

from flask import Blueprint

product = Blueprint('product', __name__)
user = Blueprint('user', __name__)