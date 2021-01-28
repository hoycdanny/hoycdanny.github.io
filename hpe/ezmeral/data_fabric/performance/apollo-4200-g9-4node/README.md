# Apollo 4200 Gen9 Data Fabric Performance

## 測試環境介紹


Apollo 4200 Gen9 *4
```
Node 1
1* CPU E5-2620 v4 @ 2.10GHz 
1* Memory 64G 
3* RI   SSD  VK000960GWSRT
9* 7.2K HDD  MB010000GWAYN
1* Mellanox Technologies MT27520 40G
2* 40G DAC Cable

Node 2
1* CPU E5-2620 v4 @ 2.10GHz 
1* Memory 64G 
3* RI   SSD  VK000960GWSRT
9* 7.2K HDD  MB010000GWAYN
1* Mellanox Technologies MT27520 40G
2* 40G DAC Cable

Node 3
1* CPU E5-2620 v4 @ 2.10GHz 
1* Memory 64G 
3* RI   SSD  VK000960GWSRT
9* 7.2K HDD  MB010000GWAYN
1* Mellanox Technologies MT27520 40G
2* 40G DAC Cable

Node 4
1* CPU E5-2620 v4 @ 2.10GHz 
1* Memory 64G 
3* RI   SSD  VK000960GWSRT
9* 7.2K HDD  MB010000GWAYN
1* Mellanox Technologies MT27520 40G
2* 40G DAC Cable

Mellanox switches SN2010 *2
```

*Note*
> Benchmark Job Fio and dd run on node 1


## 測試總結

|   Block|       讀取|    IOPS|       寫入 |    IOPS|
|--------|----------|--------|-----------|--------|
|  hdd-8k|  132MiB/s|   16.9k|  33.1MiB/s|    4234|
|hdd-256k| 1671MiB/s|    6683|   485MiB/s|    1938|
|  ssd-8k|  126MiB/s|   16.1k|  60.4MiB/s|    7725|
|ssd-256k| 1681MiB/s|    6724|   733MiB/s|    2930|


## 寫入測試

### 4node hdd write Block=>8k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1560194: Tue Jan 26 21:41:54 2021
  write: IOPS=4234, BW=33.1MiB/s (34.7MB/s)(32.3GiB/1000707msec)
    clat (usec): min=1677, max=4705.1k, avg=23589.82, stdev=75792.02
     lat (usec): min=1677, max=4705.1k, avg=23590.57, stdev=75792.02
    clat percentiles (msec):
     |  1.00th=[    3],  5.00th=[    4], 10.00th=[    5], 20.00th=[    5],
     | 30.00th=[    6], 40.00th=[    7], 50.00th=[   10], 60.00th=[   13],
     | 70.00th=[   16], 80.00th=[   21], 90.00th=[   31], 95.00th=[   62],
     | 99.00th=[  330], 99.50th=[  489], 99.90th=[ 1045], 99.95th=[ 1368],
     | 99.99th=[ 1921]
   bw (  KiB/s): min=   15, max= 1776, per=1.08%, avg=364.31, stdev=194.48, samples=186047
   iops        : min=    1, max=  222, avg=45.49, stdev=24.31, samples=186047
  lat (msec)   : 2=0.02%, 4=9.49%, 10=42.85%, 20=27.26%, 50=14.62%
  lat (msec)   : 100=2.08%, 250=2.17%, 500=1.02%, 750=0.27%, 1000=0.10%
  cpu          : usr=0.05%, sys=0.09%, ctx=4238538, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,4237994,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=33.1MiB/s (34.7MB/s), 33.1MiB/s-33.1MiB/s (34.7MB/s-34.7MB/s), io=32.3GiB (34.7GB), run=1000707-1000707msec
```
### 4node ssd write Block=>8k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1247834: Wed Jan 27 12:15:40 2021
  write: IOPS=7725, BW=60.4MiB/s (63.3MB/s)(58.9GiB/1000011msec)
    clat (usec): min=1888, max=274110, avg=12903.83, stdev=4668.98
     lat (usec): min=1889, max=274111, avg=12904.49, stdev=4668.98
    clat percentiles (msec):
     |  1.00th=[    8],  5.00th=[    9], 10.00th=[   10], 20.00th=[   11],
     | 30.00th=[   11], 40.00th=[   12], 50.00th=[   13], 60.00th=[   14],
     | 70.00th=[   15], 80.00th=[   16], 90.00th=[   17], 95.00th=[   18],
     | 99.00th=[   22], 99.50th=[   26], 99.90th=[   74], 99.95th=[   94],
     | 99.99th=[  155]
   bw (  KiB/s): min=   15, max=  816, per=1.00%, avg=619.49, stdev=66.40, samples=199437
   iops        : min=    1, max=  102, avg=77.39, stdev= 8.30, samples=199437
  lat (msec)   : 2=0.01%, 4=0.01%, 10=17.59%, 20=80.43%, 50=1.78%
  lat (msec)   : 100=0.15%, 250=0.04%, 500=0.01%
  cpu          : usr=0.07%, sys=0.15%, ctx=7726097, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,7725459,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=60.4MiB/s (63.3MB/s), 60.4MiB/s-60.4MiB/s (63.3MB/s-63.3MB/s), io=58.9GiB (63.3GB), run=1000011-1000011msec
```




### 4node hdd write Block=>256k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1482875: Tue Jan 26 21:24:06 2021
  write: IOPS=1938, BW=485MiB/s (508MB/s)(473GiB/1000098msec)
    clat (msec): min=2, max=3720, avg=51.57, stdev=64.74
     lat (msec): min=2, max=3720, avg=51.58, stdev=64.74
    clat percentiles (msec):
     |  1.00th=[    6],  5.00th=[    7], 10.00th=[    7], 20.00th=[   10],
     | 30.00th=[   15], 40.00th=[   49], 50.00th=[   64], 60.00th=[   68],
     | 70.00th=[   71], 80.00th=[   75], 90.00th=[   81], 95.00th=[   87],
     | 99.00th=[  120], 99.50th=[  251], 99.90th=[ 1099], 99.95th=[ 1351],
     | 99.99th=[ 1653]
   bw (  KiB/s): min=  509, max=13796, per=1.03%, avg=5106.18, stdev=1483.71, samples=194294
   iops        : min=    1, max=   53, avg=19.86, stdev= 5.80, samples=194294
  lat (msec)   : 4=0.02%, 10=22.47%, 20=12.41%, 50=5.26%, 100=58.14%
  lat (msec)   : 250=1.20%, 500=0.20%, 750=0.10%, 1000=0.07%
  cpu          : usr=0.05%, sys=0.13%, ctx=1938977, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,1938405,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=485MiB/s (508MB/s), 485MiB/s-485MiB/s (508MB/s-508MB/s), io=473GiB (508GB), run=1000098-1000098msec
```

### 4node ssd write Block=>256k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=933020: Wed Jan 27 11:04:25 2021
  write: IOPS=2930, BW=733MiB/s (768MB/s)(715GiB/1000030msec)
    clat (msec): min=3, max=383, avg=33.99, stdev=11.29
     lat (msec): min=3, max=383, avg=34.00, stdev=11.29
    clat percentiles (msec):
     |  1.00th=[   17],  5.00th=[   23], 10.00th=[   25], 20.00th=[   28],
     | 30.00th=[   29], 40.00th=[   31], 50.00th=[   33], 60.00th=[   35],
     | 70.00th=[   38], 80.00th=[   41], 90.00th=[   44], 95.00th=[   47],
     | 99.00th=[   71], 99.50th=[  101], 99.90th=[  150], 99.95th=[  171],
     | 99.99th=[  220]
   bw (  KiB/s): min=  512, max=14336, per=1.00%, avg=7523.77, stdev=913.06, samples=199355
   iops        : min=    2, max=   56, avg=29.30, stdev= 3.58, samples=199355
  lat (msec)   : 4=0.01%, 10=0.13%, 20=2.56%, 50=93.97%, 100=2.83%
  lat (msec)   : 250=0.50%, 500=0.01%
  cpu          : usr=0.07%, sys=0.18%, ctx=2931467, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,2930610,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=733MiB/s (768MB/s), 733MiB/s-733MiB/s (768MB/s-768MB/s), io=715GiB (768GB), run=1000030-1000030msec
```


## 讀取測試

### 4node hdd read Block=>8k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 5 (file:filesetup.c:223, func=write, error=Input/output error): pid=0: Tue Jan 26 23:14:21 2021
   read: IOPS=16.9k, BW=132MiB/s (139MB/s)(129GiB/1000023msec)
    clat (usec): min=108, max=147073, avg=5571.40, stdev=3880.19
     lat (usec): min=108, max=147073, avg=5571.69, stdev=3880.19
    clat percentiles (usec):
     |  1.00th=[  562],  5.00th=[ 1827], 10.00th=[ 3130], 20.00th=[ 3851],
     | 30.00th=[ 4228], 40.00th=[ 4555], 50.00th=[ 4883], 60.00th=[ 5211],
     | 70.00th=[ 5604], 80.00th=[ 6194], 90.00th=[ 7177], 95.00th=[13304],
     | 99.00th=[22938], 99.50th=[26608], 99.90th=[37487], 99.95th=[42730],
     | 99.99th=[55837]
   bw (  KiB/s): min=   16, max= 3392, per=1.06%, avg=1434.36, stdev=144.67, samples=188585
   iops        : min=    2, max=  424, avg=179.26, stdev=18.09, samples=188585
  lat (usec)   : 250=0.08%, 500=0.72%, 750=0.84%, 1000=0.78%
  lat (msec)   : 2=3.13%, 4=18.08%, 10=70.12%, 20=4.47%, 50=1.75%
  lat (msec)   : 100=0.02%, 250=0.01%
  cpu          : usr=0.11%, sys=1.02%, ctx=17129835, majf=0, minf=198
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=16917044,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=132MiB/s (139MB/s), 132MiB/s-132MiB/s (139MB/s-139MB/s), io=129GiB (139GB), run=1000023-1000023msec```
```
### 4node ssd read Block=>8k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: Laying out IO file (1 file / 1048576MiB)
fio: pid=0, err=5/file:filesetup.c:223, func=write, error=Input/output error
Jobs: 99 (f=99): [X(1),r(99)][100.0%][r=127MiB/s,w=0KiB/s][r=16.2k,w=0 IOPS][eta 00m:00s]
mytest: (groupid=0, jobs=100): err= 5 (file:filesetup.c:223, func=write, error=Input/output error): pid=0: Wed Jan 27 12:45:42 2021
   read: IOPS=16.1k, BW=126MiB/s (132MB/s)(123GiB/1000015msec)
    clat (usec): min=96, max=42508, avg=5730.94, stdev=2231.22
     lat (usec): min=96, max=42509, avg=5731.22, stdev=2231.22
    clat percentiles (usec):
     |  1.00th=[  578],  5.00th=[ 1893], 10.00th=[ 3425], 20.00th=[ 4359],
     | 30.00th=[ 4883], 40.00th=[ 5211], 50.00th=[ 5604], 60.00th=[ 5997],
     | 70.00th=[ 6390], 80.00th=[ 6915], 90.00th=[ 8029], 95.00th=[ 9896],
     | 99.00th=[13173], 99.50th=[14091], 99.90th=[16319], 99.95th=[17171],
     | 99.99th=[19792]
   bw (  KiB/s): min=  368, max= 4176, per=1.08%, avg=1394.36, stdev=121.70, samples=184651
   iops        : min=   46, max=  522, avg=174.26, stdev=15.22, samples=184651
  lat (usec)   : 100=0.01%, 250=0.07%, 500=0.68%, 750=0.80%, 1000=0.75%
  lat (msec)   : 2=3.03%, 4=9.35%, 10=80.50%, 20=4.80%, 50=0.01%
  cpu          : usr=0.10%, sys=1.32%, ctx=16442590, majf=0, minf=198
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=16103287,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=126MiB/s (132MB/s), 126MiB/s-126MiB/s (132MB/s-132MB/s), io=123GiB (132GB), run=1000015-1000015msec
```


### 4node hdd read Block=>256k nfs-client=>1

>fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=2548228: Wed Jan 27 01:23:57 2021
   read: IOPS=6683, BW=1671MiB/s (1752MB/s)(1632GiB/1000017msec)
    clat (usec): min=684, max=241536, avg=14957.49, stdev=5765.86
     lat (usec): min=685, max=241536, avg=14957.85, stdev=5765.87
    clat percentiles (msec):
     |  1.00th=[   10],  5.00th=[   12], 10.00th=[   12], 20.00th=[   13],
     | 30.00th=[   14], 40.00th=[   14], 50.00th=[   14], 60.00th=[   15],
     | 70.00th=[   15], 80.00th=[   16], 90.00th=[   18], 95.00th=[   23],
     | 99.00th=[   42], 99.50th=[   52], 99.90th=[   77], 99.95th=[   88],
     | 99.99th=[  115]
   bw (  KiB/s): min= 8704, max=21504, per=1.00%, avg=17107.72, stdev=1333.75, samples=199979
   iops        : min=   34, max=   84, avg=66.78, stdev= 5.22, samples=199979
  lat (usec)   : 750=0.01%, 1000=0.01%
  lat (msec)   : 2=0.01%, 4=0.01%, 10=1.44%, 20=92.63%, 50=5.38%
  lat (msec)   : 100=0.52%, 250=0.02%
  cpu          : usr=0.06%, sys=0.38%, ctx=6684750, majf=0, minf=6400
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=6683638,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=1671MiB/s (1752MB/s), 1671MiB/s-1671MiB/s (1752MB/s-1752MB/s), io=1632GiB (1752GB), run=1000017-1000017msec
```

### 4node ssd read Block=>256k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1461320: Wed Jan 27 13:02:53 2021
   read: IOPS=6724, BW=1681MiB/s (1763MB/s)(1642GiB/1000015msec)
    clat (usec): min=679, max=48419, avg=14867.21, stdev=2037.09
     lat (usec): min=679, max=48419, avg=14867.57, stdev=2037.10
    clat percentiles (usec):
     |  1.00th=[10421],  5.00th=[11994], 10.00th=[12649], 20.00th=[13435],
     | 30.00th=[13960], 40.00th=[14222], 50.00th=[14615], 60.00th=[14877],
     | 70.00th=[15533], 80.00th=[16450], 90.00th=[17695], 95.00th=[18482],
     | 99.00th=[20317], 99.50th=[21365], 99.90th=[24773], 99.95th=[26346],
     | 99.99th=[29754]
   bw (  KiB/s): min=14222, max=22016, per=1.00%, avg=17211.26, stdev=786.45, samples=199994
   iops        : min=   55, max=   86, avg=67.18, stdev= 3.08, samples=199994
  lat (usec)   : 750=0.01%, 1000=0.01%
  lat (msec)   : 2=0.01%, 4=0.01%, 10=0.64%, 20=97.96%, 50=1.40%
  cpu          : usr=0.06%, sys=0.38%, ctx=6725389, majf=0, minf=6400
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=6724230,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=1681MiB/s (1763MB/s), 1681MiB/s-1681MiB/s (1763MB/s-1763MB/s), io=1642GiB (1763GB), run=1000015-1000015msec
```


---

## 多NFS Client主機測試同時400人在線上

### 4node hdd write Block=>256k nfs-client=>4

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

> fio -filename=/mapr/my.cluster.com/hdd/h2 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

> fio -filename=/mapr/my.cluster.com/hdd/h3 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

> fio -filename=/mapr/my.cluster.com/hdd/h4 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

#### nfs-client-1

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1789467: Tue Jan 26 22:34:05 2021
  write: IOPS=656, BW=164MiB/s (172MB/s)(160GiB/1000627msec)
    clat (msec): min=2, max=9489, avg=152.17, stdev=399.22
     lat (msec): min=2, max=9489, avg=152.19, stdev=399.22
    clat percentiles (msec):
     |  1.00th=[    4],  5.00th=[    5], 10.00th=[    6], 20.00th=[    8],
     | 30.00th=[   13], 40.00th=[   21], 50.00th=[   32], 60.00th=[   47],
     | 70.00th=[   74], 80.00th=[  144], 90.00th=[  443], 95.00th=[  651],
     | 99.00th=[ 2123], 99.50th=[ 3104], 99.90th=[ 4597], 99.95th=[ 4933],
     | 99.99th=[ 5604]
   bw (  KiB/s): min=  503, max=22528, per=1.48%, avg=2492.66, stdev=1985.71, samples=134913
   iops        : min=    1, max=   88, avg= 9.66, stdev= 7.76, samples=134913
  lat (msec)   : 4=2.26%, 10=23.09%, 20=14.23%, 50=21.92%, 100=13.78%
  lat (msec)   : 250=9.62%, 500=6.83%, 750=4.39%, 1000=1.45%
  cpu          : usr=0.02%, sys=0.04%, ctx=657770, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,657089,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=164MiB/s (172MB/s), 164MiB/s-164MiB/s (172MB/s-172MB/s), io=160GiB (172GB), run=1000627-1000627msec
```

#### nfs-client-2

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=3765554: Tue Jan 26 22:33:56 2021
  write: IOPS=331, BW=82.8MiB/s (86.8MB/s)(80.9GiB/1000612msec)
    clat (msec): min=2, max=9765, avg=287.27, stdev=495.74
     lat (msec): min=2, max=9765, avg=287.29, stdev=495.74
    clat percentiles (msec):
     |  1.00th=[    5],  5.00th=[    6], 10.00th=[    9], 20.00th=[   17],
     | 30.00th=[   30], 40.00th=[   51], 50.00th=[   90], 60.00th=[  182],
     | 70.00th=[  342], 80.00th=[  485], 90.00th=[  667], 95.00th=[  986],
     | 99.00th=[ 2735], 99.50th=[ 3540], 99.90th=[ 4665], 99.95th=[ 4933],
     | 99.99th=[ 6074]
   bw (  KiB/s): min=  499, max=10752, per=1.55%, avg=1310.85, stdev=968.57, samples=129366
   iops        : min=    1, max=   42, avg= 5.06, stdev= 3.79, samples=129366
  lat (msec)   : 4=0.60%, 10=12.14%, 20=10.48%, 50=16.57%, 100=11.99%
  lat (msec)   : 250=12.73%, 500=16.53%, 750=11.05%, 1000=3.05%
  cpu          : usr=0.01%, sys=0.02%, ctx=332019, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,331371,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=82.8MiB/s (86.8MB/s), 82.8MiB/s-82.8MiB/s (86.8MB/s-86.8MB/s), io=80.9GiB (86.9GB), run=1000612-1000612msec
```

#### nfs-client-3

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=1843726: Tue Jan 26 22:34:08 2021
  write: IOPS=414, BW=104MiB/s (109MB/s)(101GiB/1000418msec)
    clat (msec): min=2, max=17354, avg=241.23, stdev=712.21
     lat (msec): min=2, max=17354, avg=241.25, stdev=712.21
    clat percentiles (msec):
     |  1.00th=[    4],  5.00th=[    6], 10.00th=[    7], 20.00th=[   11],
     | 30.00th=[   18], 40.00th=[   27], 50.00th=[   41], 60.00th=[   64],
     | 70.00th=[  111], 80.00th=[  296], 90.00th=[  558], 95.00th=[  827],
     | 99.00th=[ 3775], 99.50th=[ 5604], 99.90th=[ 8356], 99.95th=[ 9060],
     | 99.99th=[10671]
   bw (  KiB/s): min=  504, max=17920, per=1.82%, avg=1934.96, stdev=1548.13, samples=109632
   iops        : min=    1, max=   70, avg= 7.49, stdev= 6.05, samples=109632
  lat (msec)   : 4=1.04%, 10=17.96%, 20=14.18%, 50=21.78%, 100=13.44%
  lat (msec)   : 250=10.10%, 500=9.31%, 750=6.35%, 1000=1.96%
  cpu          : usr=0.01%, sys=0.03%, ctx=414856, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,414517,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=104MiB/s (109MB/s), 104MiB/s-104MiB/s (109MB/s-109MB/s), io=101GiB (109GB), run=1000418-1000418msec
```

#### nfs-client-4

```shell=
mytest: (groupid=0, jobs=100): err= 0: pid=3825371: Tue Jan 26 22:33:08 2021
  write: IOPS=798, BW=200MiB/s (209MB/s)(195GiB/1000485msec)
    clat (msec): min=3, max=16992, avg=125.22, stdev=315.66
     lat (msec): min=3, max=16992, avg=125.24, stdev=315.66
    clat percentiles (msec):
     |  1.00th=[    5],  5.00th=[    6], 10.00th=[    7], 20.00th=[   13],
     | 30.00th=[   23], 40.00th=[   35], 50.00th=[   50], 60.00th=[   71],
     | 70.00th=[   86], 80.00th=[  142], 90.00th=[  380], 95.00th=[  550],
     | 99.00th=[  885], 99.50th=[ 1070], 99.90th=[ 2265], 99.95th=[ 6812],
     | 99.99th=[13087]
   bw (  KiB/s): min=  506, max=18944, per=1.19%, avg=2427.65, stdev=2088.35, samples=168365
   iops        : min=    1, max=   74, avg= 9.42, stdev= 8.16, samples=168365
  lat (msec)   : 4=0.61%, 10=16.27%, 20=10.34%, 50=23.18%, 100=23.95%
  lat (msec)   : 250=12.01%, 500=7.20%, 750=4.56%, 1000=1.25%
  cpu          : usr=0.02%, sys=0.05%, ctx=799086, majf=0, minf=0
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,798523,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=200MiB/s (209MB/s), 200MiB/s-200MiB/s (209MB/s-209MB/s), io=195GiB (209GB), run=1000485-1000485msec
```



