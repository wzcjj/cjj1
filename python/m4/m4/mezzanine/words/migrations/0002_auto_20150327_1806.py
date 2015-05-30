# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import mezzanine.core.fields
from django.conf import settings
import mezzanine.utils.models


class Migration(migrations.Migration):

    dependencies = [
        ('sites', '0001_initial'),
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
        ('words', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='WordsCategory',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('title', models.CharField(verbose_name='Title', max_length=500)),
                ('slug', models.CharField(verbose_name='URL', help_text='Leave blank to have the URL auto-generated from the title.', blank=True, max_length=2000, null=True)),
                ('site', models.ForeignKey(editable=False, to='sites.Site')),
            ],
            options={
                'verbose_name': 'Blog Category',
                'verbose_name_plural': 'Blog Categories',
                'ordering': ('title',),
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='WordsPost',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, primary_key=True, auto_created=True)),
                ('comments_count', models.IntegerField(editable=False, default=0)),
                ('keywords_string', models.CharField(editable=False, blank=True, max_length=500)),
                ('rating_count', models.IntegerField(editable=False, default=0)),
                ('rating_sum', models.IntegerField(editable=False, default=0)),
                ('rating_average', models.FloatField(editable=False, default=0)),
                ('title', models.CharField(verbose_name='Title', max_length=500)),
                ('slug', models.CharField(verbose_name='URL', help_text='Leave blank to have the URL auto-generated from the title.', blank=True, max_length=2000, null=True)),
                ('_meta_title', models.CharField(verbose_name='Title', help_text='Optional title to be used in the HTML title tag. If left blank, the main title field will be used.', blank=True, max_length=500, null=True)),
                ('description', models.TextField(verbose_name='Description', blank=True)),
                ('gen_description', models.BooleanField(verbose_name='Generate description', help_text='If checked, the description will be automatically generated from content. Uncheck if you want to manually set a custom description.', default=True)),
                ('created', models.DateTimeField(editable=False, null=True)),
                ('updated', models.DateTimeField(editable=False, null=True)),
                ('status', models.IntegerField(verbose_name='Status', choices=[(1, 'Draft'), (2, 'Published')], help_text='With Draft chosen, will only be shown for admin users on the site.', default=2)),
                ('publish_date', models.DateTimeField(verbose_name='Published from', help_text="With Published chosen, won't be shown until this time", blank=True, null=True)),
                ('expiry_date', models.DateTimeField(verbose_name='Expires on', help_text="With Published chosen, won't be shown after this time", blank=True, null=True)),
                ('short_url', models.URLField(blank=True, null=True)),
                ('in_sitemap', models.BooleanField(verbose_name='Show in sitemap', default=True)),
                ('content', mezzanine.core.fields.RichTextField(verbose_name='Content')),
                ('allow_comments', models.BooleanField(verbose_name='Allow comments', default=True)),
                ('featured_image', mezzanine.core.fields.FileField(verbose_name='Featured Image', blank=True, max_length=255, null=True)),
                ('categories', models.ManyToManyField(verbose_name='Categories', related_name='blogposts', blank=True, to='words.WordsCategory')),
                ('related_posts', models.ManyToManyField(verbose_name='Related posts', related_name='related_posts_rel_+', blank=True, to='words.WordsPost')),
                ('site', models.ForeignKey(editable=False, to='sites.Site')),
                ('user', models.ForeignKey(related_name='wordsposts', to=settings.AUTH_USER_MODEL, verbose_name='Author')),
            ],
            options={
                'verbose_name': 'Blog post',
                'verbose_name_plural': 'Blog posts',
                'ordering': ('-publish_date',),
            },
            bases=(models.Model, mezzanine.utils.models.AdminThumbMixin),
        ),
        migrations.RemoveField(
            model_name='blogcategory',
            name='site',
        ),
        migrations.DeleteModel(
            name='BlogCategory',
        ),
        migrations.RemoveField(
            model_name='blogpost',
            name='categories',
        ),
        migrations.RemoveField(
            model_name='blogpost',
            name='related_posts',
        ),
        migrations.RemoveField(
            model_name='blogpost',
            name='site',
        ),
        migrations.RemoveField(
            model_name='blogpost',
            name='user',
        ),
        migrations.DeleteModel(
            name='BlogPost',
        ),
    ]
