import json, boto3, time

def lambda_handler(event, context):
   subject = event.get('subject', None)
   image_url = event.get('image_url', None)
   
   db = boto3.resource('dynamodb')
   galleryTable = db.Table('Gallery')
   
   galleryId = int(time.time())
   
   res = galleryTable.put_item(
       Item = {
           'id': galleryId,
           'subject': subject,
           'image_url': image_url
       })
   
   return {
       'statusCode': 200
   }