#! /usr/bin/env	python2.7
# -*- coding: utf-8 -*-
#coding=utf-8

#coding=gbk


#print '100 + 200 = ',100 + 200 
#name = raw_input('please input your name:')
#print 'hello',name

#print absolute 'value of an interger:'

'''
#if语句后面是:号
a = 100
if a >= 0:
	print a
else:
	print -a

#在字符串内部包含'又包含" 可以用转义字符\来标示
'I\'m \"OK\"!'
I'm "OK"!
'''

'''
print 'I\'m ok.'
print 'I\'m learning\n Python.'
print '\\\n\\'
'''

#如果字符串里面有很多字符都需要转义，就需要加很多\，为了简化，python还允许用r''表示''内部的字符串默认不转义，

'''
print '\\\t\\'
print r'\\\t\\'
'''
#如果字符串内部有很多换行，用\n写在一行里面不好阅读，为了简化，python允许使用'''...'''的格式表示多行内容。
"""
print '''line1
line2
line3'''
"""
#在交互式命令里面输入为print '''line1
#						...line2
#						...line3'''

#多行字符串'''...'''还可以在前面加上r使用

"""
print r'''line1
line2
line3'''
"""

#and运算是与运算，只有所有都为True，and结果才是True
#or运算是或运算，只要其中有一个为True,or运算结果就是True
#not运算是非运算，它是一个单目运算符，把True变成False,False变成True
"""
age = 20
if age >= 18:
	print 'adult'
else:
	print 'teenager'
"""
#空值是python里一个特殊的值，用None表示，None不能理解为0，因为0是有意义的，而None是一个特殊的空值

#变量的概念和C语言中的一样，变量名必须是大小写字母，数字，下划线组成

#在python中，等号=是赋值语句，可以把任意数据类型赋值给变量，同一个变量可以反复赋值，而且可以是不同类型的变量
"""
a = 123
print a
a = 'ABC'
print a
"""
"""
理解变量在计算机内存中的表示也非常重要
a = 'ABC'
此时python解释器干了两件事情
1.在内存中创建了一个'ABC'的字符串
2.在内存中创建了一个名为a的变量，并把它指向'ABC'
"""
"""
a = 'ABC'	#解释器创建了字符串'ABC'和变量a,并把a指向'ABC'
b = a		#解释器创建了变量b，并把b指向a指向的字符串'ABC'
a = 'XYZ'	#解释器创建了字符串'XYZ'并把a的指向改为'XYZ'，但b没有改变
print b
"""
#最后一行打印的是ABC

"""
所谓常量就是不能改变的变量，在python中，用大写的变量名表示常量
但是其仍然是一个变量，只是人们的习惯不能去改变其而已
"""
#因为python的诞生比Unicode标准发布的时间还要早，所以最早的python只支持ASCII编码，普通的字符串'ABC'在python内部都是ASCII编码的，python提供了ord()函数和chr()函数，可以把字母和对应的数字相互转换
"""
ord('A')
65
chr(65)
'A'
"""
"""
python在后来添加了对Unicode的支持，以Unicode表示的字符串用u'....'
print u'中文'
中文
u'中'
u'\u4e2d
写u'中'和u'\u4e2d'是一样的，\u后面是十六进制的Unicode码，因此，u'A'和u'\u0041'也是一样的
两种字符串如何相互转换，字符串'xxx'虽然是ASCII编码，但也可以看成是UTF-8编码，而u'xxx'则只能是Unicode编码
把u'xxx'转换为UTF-8编码的'xxx'用encode('utf-8')

u'ABC',encode('utf-8')
'ABC'
u'中文',encode('utf-8')
'\xe4\xb8\xad\xe6\x96\x87'
"""

"""
在python中，采用的格式化方式和C语言是一致的，用%实现

'Hello,%s' % 'world'
'Hello world'
'Hi,%s,you have $%d.' % ('Michael',1000000)
'Hi,Micheal,you have $1000000.'
%运算符就是用来格式化字符串的，在字符串内部，%s表示用字符串替换，%d表示用整数替换，有几个%?占位符，后面就要跟几个变量或者值，顺序要对应好。如果只有一个%?，括号可以省略.
c常见的占位符有:
%d整数
%f浮点数
%s字符串
%x十六进制整数
	'%2d-%02d' %(3,1)
	'3-01'
	'%.2f'	% 3.1415926
	'3.14'
"""
#使用list和tuple
"""
list
python内置的一种数据类型是列表:list.list是一种有序的集合，可以随时添加和删除其中的元素。
"""
"""
classmates = ['Micheal','Bob','Tracy']
print classmates
print len(classmates)
"""
"""
	当索引超出了范围时，python就会报一个IndexError错误，所以，要确保索引不要越界，记得最后一个元素的索引为len(calssmates)-1
如果要取最后一个元素，除了计算索引位置外，还可以用-1做索引，直接获取最后一个元素。
	list时一个可变的有序表，所以，可以往list中追加元素到末尾
	classmates.append('Adam')
	也可以把元素插入到指定的位置，比如索引为1的位置
	classmates.insert(1.'jack')
	要删除list末尾的元素，用pop方法
	classmates.pop()
	要删除指定位置的元素，用pop(i)方法，其中i是索引位置
	classmates.pop(i)
	要把某个元素替换成别的元素，可以直接赋值给对应的索引位置
	classmates[1] = 'Sarash'
	list里面的元素的数据类型也可以不同
	L = {'Apple',123,True};
	list元素也可以是另一个list，
	s = {'python','java',['asp','php'],'schmem'};
	注意s只有4个元素，其中s[2]又是一个list，如果拆开就更容易理解
	p = ['asp','php'];
	s = ['python','java',p,'scheme']
	要拿到'php'可以写p[1]或者s[2][1],因此s可以看成是一个二维数组
	如果一个list中一个元素也没有，就是一个空的list,它的长度为0

"""

"""
tuple
另一种有序列表叫元组：tuple,tuple和list非常类似，但是tuple一旦初始化就不能被修改，
	classmates = ('Micheal','Bob','Tracy')
	现在,classmates这个tuple不能变了，它也没有append()，insert()这样的方法。其他获取元素的方法和list是一样的，你可以正常使用classmates[0],classmates[-1],但不能赋值成另外的元素
	t = (1,2)
	t
	(1,2)
	如果要定义一个空的tuple，可以写成()
	t = ()
	t
	()
	但是，要定义一个只有一个元素的tuple,如果你这样定义
	t = (1)
	t
	定义的不是tuple,是1这个数，因为括号()既可以表示tuple,又可以表示数学公式中的小括号，这样就产生了歧义，
	所以，只有一个元素的tuple定义时必须加一个逗号,来消除歧义
	t = (1,)
	t
	(1,)
	python在显示只有1个元素的tuple时，也会加一个逗号,，以免弄成数学意义上的括号
	下面来看一个"可变的"tuple
	t = ('a','b',['A','B'])
	t[2][0] = 'X'
	t[2][1] = 'Y'
	t
	('a','b',['X','Y'])
	表面上看，tuple的元素确实变了，但其实变的不是tuple的元素，而是list的元素。tuple一开始指向的list并没有变成别的list。tuple的每个元素，指向永远不变，即指向'a',就不能改成指向'b',指向一个list,就不能改成指向其他一个对象，但指向的list本身是可变的。
"""






























