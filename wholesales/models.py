from django.db import models
from django.contrib.auth.models import User

class Wholesale(models.Model):
    Name            = models.CharField(max_length=50)
    AuthorizationNr = models.CharField(max_length=40)
    CreationDate    = models.DateField()
    PostalCode      = models.ForeignKey(
        'main.PostalCode'
    )
    Street          = models.CharField(max_length=10)

    class Meta:
        db_table    = "Wholesales"



class Saler(models.Model):
    UserId          = models.ForeignKey(
        User
    )
    WholesaleId     = models.ForeignKey(
        'Wholesale'
    )
    EmploymentDate  = models.DateField()

    class Meta:
        db_table    = "Salers"

class WholesaleProduct(models.Model):
    MedicineId      = models.ForeignKey(
        'main.Medicine'
    )
    WholesaleId     = models.ForeignKey(
        'Wholesale'
    )
    Price           = models.FloatField()
    class Meta:
        db_table    = "WholesalesProducts"
