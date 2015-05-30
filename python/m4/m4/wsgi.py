from __future__ import unicode_literals

import os
import sys

from django.core.wsgi import get_wsgi_application

from os.path import join,dirname,abspath
 
PROJECT_DIR = dirname(dirname(abspath(__file__)))#3
sys.path.insert(0,PROJECT_DIR) # 5

PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))
PROJECT_PARENT = PROJECT_ROOT.rsplit("/", 1)[0]
sys.path.extend([PROJECT_ROOT, PROJECT_PARENT])
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "settings")

application = get_wsgi_application()
