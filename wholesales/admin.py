from django.contrib import admin

from .models import Wholesale
from .models import WholesaleProduct

class WholesaleAdmin(admin.ModelAdmin):
    fields = []

admin.site.register(Wholesale, WholesaleAdmin)
admin.site.register(WholesaleProduct)
