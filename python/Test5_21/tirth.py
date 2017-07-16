#!/usr/bin/env python2.7
# -*- coding: utf-8 -*-

#coding=gbk


"""
可以根据年龄不同打印不同的内容
age = 20
if age >= 18:
	print 'your age is ',age
	print 'adult'
"""

#根据python的缩进规则，如果if语句判断是True，就把缩进的两行print语句执行了，否则，什么也不做。
"""
age = 3
if age >= 18:
	print 'your age is',age
	print 'adult'
else:
	print 'your age is',age
	print 'tenager'
"""

#当然上面的判断是很粗略的，完全可以用elif做更细致的判断
"""
age = 3
if age >= 18:
	print 'adult'
elif age >= 6:
	print 'teenager'
else:
	print 'kid'
"""
#elif是else if 的缩写，完全可以有多个elif,所以这个if语句的完整评价就是
"""
	if<条件判断>:
		<执行1>
	elif<条件判断2>:
		<执行2>
	elif<条件判断3>:
		<执行3>
	else:
		<执行4>
	if语句执行有个特点，它是从上往下判断，如果在某个判断上是True,把该判断对应的语句执行后，就忽略剩下的elif和else
"""
"""
age = 20
if age >= 6:
	print 'teenager'
elif age >= 18:
	print 'adult'
else:
	print 'kid'
"""	
#if判断条件和C语言中的判断条件是类似的

#循环
#python的循环有两种，一种是for...in循环，依次把list或者tuple中的每个元素迭代出来
"""
names = ['Michael','Bob','Tracy']
for	name in names:
	print name
"""

"""
执行这段代码，会依次打印names的每一个元素
所以for x in ...循环就是把每个元素代入变量x，然后依次执行缩进块的语句
再比如我们想计算1-10的整数之和，可以用一个sum变量做累加
"""
"""
sum = 0
for x in [1,2,3,4,5,6,7,8,9,10]:
	sum = sum + x
print sum
"""

#如果要计算1-100的整数之和，从1写到100有点困难，幸好python提供了一个range()函数，可以生成一个整数序列，比如range(5)生成的序列是从0开始小于5的整数
"""
range(5)
[0,1,2,3,4]
range(101)就可以生成0-100的整数序列
"""
"""
sum = 0
for x in range(101):
	sum = sum + x
print sum
"""
#第二种循环是while循环，只要条件满足，就不断循环，条件不满足时退出循环。
"""
sum = 0
n = 99
while n > 0:
	sum = sum + n
	n = n - 2
print sum
"""
#再议raw_input
"""
birth = raw_input('birth:')
if birth < 2000:
	print '00前'
else:
	print '00后'
"""
#输入1982，结果却显示00后
#原因是从raw_input()中读取的内容永远以字符串的形式返回，把字符串和整数比较就不会得到期待的结果，必须先用int()把字符串转换为整型
"""
birth = int(raw_input('birth:'))
if birth < 2000:
	print '00前'
else:
	print '00后'
"""
#但是如果输入abc呢，程序会退出，是因为int()发现一个字符串并不是合法的数字时就会报错

'''
	python内置了字典，dict的支持，dict全称dictionary,再其他语言中也称为map,使用键-值(key-value)存储，具有极快的查找速度
	举个例子，假设要根据同学的名字查找对应的成绩，如果用list实现，需要两个list
	names = ['Michael','Bob','Tracy']
	scores = [95,75,85]
	给定一个名字，要查找对应的成绩，就先要再names中找到对应的位置，list越长，耗时越长
	如果用dict实现，只需要一个"名字","成绩"的对照表,直接根据名字查找成绩，无论这个表有多大，查找速度都不会变慢，用python写一个dict如下，
	d = {'Michael':95,'Bob':75,'Tracy':85}
	d['Michael']

	为什么dict查找速度这么快，因为dict的实现原理和查字典是一样的，假设字典包含了一万个汉字，我们要查一个汉字，一个办法是从字典第一页往后翻，直到我们找到想要的字为止，这种方法就是在list中查找元素的方法，list越大，查找越满。
	第二种方法就是先在字典的索引里，查这个字对应的页码，然后直接翻到该页，找到这个字，无论查哪个字，这种速度都特别快。
	dict就是第二种实现方式，
	把数据放入dict的方法，除了初始化时指定外，还可以通过key放入
	d['Adam'] = 67
	由于一个key只能对应一个value,所以多次对一个key放入value,后面的值会把前面的值冲掉
	d['jack'] = 90
	d['jack'] = 88

	如果key不存在，dict就会报错
	要避免key不存在的错误，有两种方法，一是通过in判断key是否存在
	'Thomas' in d
	二是通过dict提供的get方法，如果key不存在，可以返回None,或者自己指定的value
	d.get('Thomas')
	d.get('Thomas',-1)
	注意 返回None的时候python的交互式命令不显示结果
	要删除一个key值，用pop(key)方法，对应的value也会从dict中删除
	d.pop('Bob')

	请务必注意，dict内部存放的顺序和key放入的顺序是没有关系的
	和list比较，dict有以下几个特点：
	1.查找和插入的速度极快，不会随着key的增加而增加
	2.需要占用大量的内存，内存浪费多
	而list刚好相反
	所以dict是用空间来换取时间的一种方法
	dict可以用在需要高速查找的很多地方，在Python代码中无处不在
	这是因为dict根据key来计算value的存储位置，如果每次计算相同的key得出的结果不同，那dict内部就完全混乱了，这个通过key计算位置的算法称为哈希算法
	要保证hash的正确性，作为key的对象就不能变。在python中，字符串，整数都是不可变的，因此，可以放心地作为key。而list是可变的，就不能作为key

'''


"""
	set和dict类似，也是一组key的集合，但不存储value.由于key不重复，所以，在set中，没有重复的key。
	要创建一个set,需要提供一个list作为输入集合
	注意，传入的参数[1,2,3]是一个list,而显示的set([1,2,3])只是告诉你这个set内部有1,2,3这3个元素，显示的[]不表示这是一个list
	重复元素在set中自动被过滤
	通过add(key)方法可以添加元素到set中，
	通过remove(key)方法可以删除元素
	set可以看成是数学意义上的无序和无重复元素的集合，因此两个set可以做数学意义上的交集并集等操作
	set和dict的唯一区别仅在于没有存储对应的value,但是，set的原理和dict一样，所以，同样不可以放入可变对象，因为无法判断两个可变对象是否相等，因为无法判断两个可变对象是否相等。
"""


"""
	str是不变对象，而list是可变对象
	a = ['c','b','a']
	a.sort()
	a	['a','b','c']
	对于不可变对象，比如str,对str进行操作
	a = 'abc'
	a.replace('a','A')
	a的值依旧没有改变
	虽然字符串有个replace()方法，也确实变出了'Abc',但变量a最后仍然是'abc'
	要始终牢记的是，a是变量，而'abc'才是字符串对象，有些时候，我们经常说，对象a的内容是'abc',但其实是指，a本身是一个变量，它指向对象的内容才是'abc'
	相当于C语言中的指针功能
	当我们调用a.replace('a','A')时，实际上调用方法replace是作用在字符串对象'abc'上的，而这个方法虽然名字叫replace,但却没有改变字符串'abc'的内容。相反，replace的方法创建了一个新字符串'Abc'并返回，如果我们用变量b指向该新字符串，就容易理解了，变量a仍指向原有的字符串'abc',但变量b却指向新字符串'Abc'了
	所以，对于不变对象来说，调用对象自身的任意方法，也不会改变对象自身的内容。相反，这些方法会创建新的对象并返回，这样，就保证了不可变对象本身永远是不可变的。
"""













