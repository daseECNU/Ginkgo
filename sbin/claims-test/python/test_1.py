# -*- coding: utf-8 -*-

import urllib
import urllib2
import threading
import time
url = "http://219.228.147.162:8097"
threads = []
threads_name = []
def send_request(turns, f,fd_):
	file_ = open(threads_name[fd_],'w+')
	file_r = open(f,'r')
	for i in range (turns):
		request_str = ''
		while True:
			c = file_r.read(1)
			if not c : break
			if c == ';':
				request_str += c
				print request_str
				try:
					req = urllib2.Request(url + urllib.quote("/CLAIMS/"+request_str))
					res_data = urllib2.urlopen(req)
					res = res_data.read()
					file_.write(res)

				except :
					raise
				finally:
					#f0.write(res)
					request_str = ""
			else:
			#	if c == 10 :
			#		request_str += " "
				request_str += c
			#time.sleep(0.1)
		file_r.seek(0,0)
	file_.close()
	file_r.close()


def init_threads(thread_numbers, threads, turns, file):
	for i in range(thread_numbers):
		str_temp = 'Thread'+str(i)
		threads_name.append(str_temp)
	for i in range(thread_numbers):
		t = threading.Thread(target = send_request, args = (turns, file,i))
		threads.append(t)




if __name__ == '__main__':
	#f0 = open ('out','w+')
	#file_name = raw_input('input the testcase pls: ')
	#file_name = '/home/imdb/git/CLAIMS/sbin/claims-test/python/' + file_name + '.test'
	file_name = '/home/imdb/git/CLAIMS/sbin/claims-test/python/sql1.test'
	#repeat_turns = raw_input('input the turns of: ')
	#repeat_turns = int(repeat_turns) - int('0')
	repeat_turns = 1
	thread_numbers = 1
	#thread_numbers = raw_input('input the thread_numbers: ')
	#thread_numbers = int(thread_numbers) - int('0')
	init_threads(thread_numbers, threads, repeat_turns, file_name)
	for t in threads:
#		if t == threads[1]:
#			time.sleep(0.1)
			
		t.setDaemon(True)
		t.start()
	for t in threads:
		t.join()



	#flag = false
#	request_str = ""
#	while True:
#		c = f.read(1)
#		if not c : break
#		if c == ';':
#			request_str += c
#			print request_str
#			try:
#				req = urllib2.Request(url + urllib.quote("/CLAIMS/"+request_str))
#				res_data = urllib2.urlopen(req)
#			#	res = res_data.read()
#			#	print res
#			#except Exception, e:
#				#raise e
#
	#		#f0.write(res)
	#		#request_str = ""

	#		#continue
	#	request_str += c
	#f0.close()
	#f.close()



	#req = urllib2.Request(url + urllib.quote("/CLAIMS:select * from trade where trade_no = 1;"))

	#res_data = urllib2.urlopen(req)
	#res = res_data.read()
	#print res


