import json, boto3

def lambda_handler(event, context):
    galleryId = event.get('id', None)
    
    db = boto3.resource('dynamodb')
    galleryTable = db.Table('Gallery')
    
    res = galleryTable.delete_item(
        Key = {
            'id': galleryId
        }
    )
    
    return{
        "statusCode" : 200
    }