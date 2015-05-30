from django.conf.urls import patterns, include, url
from django.contrib import admin
from cms1 import views
urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'cms.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    (r'^articles/(\d{4})/$', views.year_archive),
    (r'^articles/(\d{4})/(\d{2})/$', views.month_archive),
    (r'^articles/(\d{4})/(\d{2})/(\d+)/$', views.article_detail),
    
    url(r'^$', views.index, name='home'),# Notice this line 

    url(r'^admin/', include(admin.site.urls)),
)