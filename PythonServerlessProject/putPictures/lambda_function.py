import json, boto3

def lambda_handler(event, context):
    galleryId = event.get('id', None)
    subject = event.get('subject', None)
    image_url = event.get('image_url', None)
    
    db = boto3.resource('dynamodb')
    galleryTable = db.Table('Gallery')
    
    res = galleryTable.update_item(
        Key = {
            'id' : galleryId
            
        },
        UpdateExpression = "set subject =:subject, image_url =:image_url",
        ExpressionAttributeValues = {
            ":subject" : subject,
            ":image_url" : image_url
        }
    )
    
    return{
        "statusCode" : 200
    }