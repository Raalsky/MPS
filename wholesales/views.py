from django.shortcuts import render
from django.http import HttpResponse

from .models import WholesaleProduct

def index(request):
    context = {}
    return render(request, 'wholesales/index.html', context)

def products(request):
    context = {
        'products': WholesaleProduct.objects.all()
    }
    return render(request, 'wholesales/products.html', context)
