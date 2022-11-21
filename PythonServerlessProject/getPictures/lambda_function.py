import json, boto3, decimal

def lambda_handler(event, context):
    db = boto3.resource('dynamodb')
    galleryTable = db.Table('Gallery')

    res = galleryTable.scan()['Items']
    res = json.dumps(res, cls = DecimalEncoder)
    res = json.loads(res)

    return res
    
# Decmial -> Int
class DecimalEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, decimal.Decimal):
            return int(obj)
        return super(DecimalEncoder, self).default(obj)