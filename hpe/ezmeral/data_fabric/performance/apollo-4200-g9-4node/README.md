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

|    Type|   Block|  Direct|   iodepth|  ioengine|      size|   numjobs|        rw|      Read|Read/IOPS|      Write|Write/IOPS|
|-------:|-------:|-------:|---------:|---------:|---------:|---------:|---------:|---------:|--------:|----------:|---------:|
|     hdd|      1M|       1|        64|    libaio|       1TB|         8|Sequential|  812MiB/s|      805|   416MiB/s|       416|
|     ssd|      1M|       1|        64|    libaio|       1TB|         8|Sequential|  811MiB/s|      811|   405MiB/s|       126|
|     hdd|      4k|       1|        64|    libaio|       1TB|         8|    Random|   36.5MiB|     9334|    20MiB/s|      5132|
|     ssd|      4k|       1|        64|    libaio|       1TB|         8|    Random|   44.1MiB|    11.3k|  21.2MiB/s|      5425|
|     hdd|      8k|       1|         1|     psync|       1TB|       100|    Random|  132MiB/s|    16.9k|  33.1MiB/s|      4234|
|     hdd|    256k|       1|         1|     psync|       1TB|       100|    Random| 1671MiB/s|     6683|   485MiB/s|      1938|
|     ssd|      8k|       1|         1|     psync|       1TB|       100|    Random|  126MiB/s|    16.1k|  60.4MiB/s|      7725|
|     ssd|    256k|       1|         1|     psync|       1TB|       100|    Random| 1681MiB/s|     6724|   733MiB/s|      2930|

## Test IOPS by performing random writes, using an I/O block size of 4 KB and an I/O depth of at least 64

### hdd write IOPS
> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 64 -thread -rw=randwrite -ioengine=libaio -bs=4K -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3567633: Thu Jan 28 12:16:17 2021
  write: IOPS=5132, BW=20.0MiB/s (21.0MB/s)(1208MiB/60264msec)
    slat (usec): min=2, max=363, avg=15.51, stdev= 6.51
    clat (usec): min=1728, max=3720.1k, avg=99686.62, stdev=183649.76
     lat (usec): min=1746, max=3720.1k, avg=99702.58, stdev=183650.09
    clat percentiles (msec):
     |  1.00th=[    3],  5.00th=[    5], 10.00th=[    6], 20.00th=[    9],
     | 30.00th=[   15], 40.00th=[   24], 50.00th=[   45], 60.00th=[   86],
     | 70.00th=[  107], 80.00th=[  124], 90.00th=[  176], 95.00th=[  368],
     | 99.00th=[ 1045], 99.50th=[ 1167], 99.90th=[ 1770], 99.95th=[ 2056],
     | 99.99th=[ 2735]
   bw (  KiB/s): min=  160, max= 4440, per=12.53%, avg=2572.76, stdev=1194.31, samples=960
   iops        : min=   40, max= 1110, avg=643.17, stdev=298.59, samples=960
  lat (msec)   : 2=0.03%, 4=3.11%, 10=19.66%, 20=14.06%, 50=14.55%
  lat (msec)   : 100=14.41%, 250=26.89%, 500=3.58%, 750=1.67%, 1000=0.89%
  cpu          : usr=0.68%, sys=1.21%, ctx=288233, majf=0, minf=8
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.1%, 32=0.1%, >=64=99.8%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=0,309289,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
  WRITE: bw=20.0MiB/s (21.0MB/s), 20.0MiB/s-20.0MiB/s (21.0MB/s-21.0MB/s), io=1208MiB (1267MB), run=60264-60264msec
```

### ssd write IOPS
> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 64 -thread -rw=randwrite -ioengine=libaio -bs=4K -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3586340: Thu Jan 28 12:20:16 2021
  write: IOPS=5425, BW=21.2MiB/s (22.2MB/s)(1275MiB/60183msec)
    slat (usec): min=2, max=385, avg=15.48, stdev= 6.29
    clat (msec): min=2, max=1668, avg=93.74, stdev=71.16
     lat (msec): min=2, max=1668, avg=93.75, stdev=71.16
    clat percentiles (msec):
     |  1.00th=[   23],  5.00th=[   50], 10.00th=[   53], 20.00th=[   56],
     | 30.00th=[   62], 40.00th=[   74], 50.00th=[   94], 60.00th=[  100],
     | 70.00th=[  104], 80.00th=[  110], 90.00th=[  118], 95.00th=[  129],
     | 99.00th=[  493], 99.50th=[  701], 99.90th=[  818], 99.95th=[  852],
     | 99.99th=[  860]
   bw (  KiB/s): min=   16, max= 3536, per=12.60%, avg=2733.24, stdev=846.83, samples=954
   iops        : min=    4, max=  884, avg=683.28, stdev=211.71, samples=954
  lat (msec)   : 4=0.01%, 10=0.23%, 20=0.59%, 50=5.21%, 100=56.37%
  lat (msec)   : 250=35.60%, 500=1.00%, 750=0.66%, 1000=0.33%
  cpu          : usr=0.70%, sys=1.31%, ctx=302484, majf=0, minf=8
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.1%, 32=0.1%, >=64=99.8%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=0,326522,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
  WRITE: bw=21.2MiB/s (22.2MB/s), 21.2MiB/s-21.2MiB/s (22.2MB/s-22.2MB/s), io=1275MiB (1337MB), run=60183-60183msec
```

### hdd read IOPS
> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 64 -thread -rw=randread -ioengine=libaio -bs=4K -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3577362: Thu Jan 28 12:18:06 2021
   read: IOPS=9334, BW=36.5MiB/s (38.2MB/s)(2189MiB/60030msec)
    slat (usec): min=2, max=839, avg=12.99, stdev= 5.19
    clat (usec): min=525, max=170195, avg=54817.14, stdev=42889.56
     lat (usec): min=534, max=170205, avg=54830.55, stdev=42889.62
    clat percentiles (usec):
     |  1.00th=[  1631],  5.00th=[  2376], 10.00th=[  3195], 20.00th=[  5473],
     | 30.00th=[ 10421], 40.00th=[ 23200], 50.00th=[ 65274], 60.00th=[ 83362],
     | 70.00th=[ 91751], 80.00th=[ 95945], 90.00th=[105382], 95.00th=[115868],
     | 99.00th=[129500], 99.50th=[135267], 99.90th=[143655], 99.95th=[145753],
     | 99.99th=[147850]
   bw (  KiB/s): min= 3240, max= 6360, per=12.49%, avg=4664.59, stdev=497.18, samples=960
   iops        : min=  810, max= 1590, avg=1166.12, stdev=124.30, samples=960
  lat (usec)   : 750=0.01%, 1000=0.03%
  lat (msec)   : 2=2.66%, 4=11.50%, 10=15.18%, 20=9.23%, 50=7.15%
  lat (msec)   : 100=40.26%, 250=13.98%
  cpu          : usr=1.04%, sys=1.99%, ctx=535103, majf=0, minf=520
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.1%, 32=0.1%, >=64=99.9%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=560346,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
   READ: bw=36.5MiB/s (38.2MB/s), 36.5MiB/s-36.5MiB/s (38.2MB/s-38.2MB/s), io=2189MiB (2295MB), run=60030-60030msec
```

### ssd read IOPS
> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 64 -thread -rw=randread -ioengine=libaio -bs=4K -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3607785: Thu Jan 28 12:24:59 2021
   read: IOPS=11.3k, BW=44.1MiB/s (46.2MB/s)(2646MiB/60034msec)
    slat (usec): min=2, max=404, avg=12.61, stdev= 5.35
    clat (usec): min=330, max=107770, avg=45346.97, stdev=19836.31
     lat (usec): min=340, max=107784, avg=45359.98, stdev=19836.42
    clat percentiles (msec):
     |  1.00th=[    4],  5.00th=[   11], 10.00th=[   19], 20.00th=[   30],
     | 30.00th=[   34], 40.00th=[   39], 50.00th=[   44], 60.00th=[   52],
     | 70.00th=[   61], 80.00th=[   64], 90.00th=[   70], 95.00th=[   78],
     | 99.00th=[   86], 99.50th=[   89], 99.90th=[   94], 99.95th=[   96],
     | 99.99th=[  103]
   bw (  KiB/s): min= 4304, max= 7024, per=12.50%, avg=5639.53, stdev=505.73, samples=960
   iops        : min= 1076, max= 1756, avg=1409.87, stdev=126.44, samples=960
  lat (usec)   : 500=0.02%, 750=0.06%, 1000=0.08%
  lat (msec)   : 2=0.33%, 4=0.94%, 10=3.50%, 20=6.06%, 50=46.99%
  lat (msec)   : 100=42.00%, 250=0.02%
  cpu          : usr=1.21%, sys=2.30%, ctx=646515, majf=0, minf=520
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.1%, 32=0.1%, >=64=99.9%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=677359,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
   READ: bw=44.1MiB/s (46.2MB/s), 44.1MiB/s-44.1MiB/s (46.2MB/s-46.2MB/s), io=2646MiB (2774MB), run=60034-60034msec
```


## Test throughput by performing sequential writes with multiple parallel streams (8+), using an I/O block size of 1 MB and an I/O depth of at least 64

### hdd write throughput
> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 64 -thread -rw=write -ioengine=libaio -bs=1M -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3463327: Thu Jan 28 11:53:31 2021
  write: IOPS=416, BW=416MiB/s (436MB/s)(25.3GiB/62182msec)
    slat (usec): min=90, max=1647, avg=255.36, stdev=58.21
    clat (msec): min=4, max=9113, avg=1165.52, stdev=1071.69
     lat (msec): min=4, max=9114, avg=1165.77, stdev=1071.69
    clat percentiles (msec):
     |  1.00th=[   42],  5.00th=[  131], 10.00th=[  234], 20.00th=[  481],
     | 30.00th=[  751], 40.00th=[  894], 50.00th=[ 1028], 60.00th=[ 1167],
     | 70.00th=[ 1368], 80.00th=[ 1536], 90.00th=[ 1838], 95.00th=[ 2089],
     | 99.00th=[ 7483], 99.50th=[ 7953], 99.90th=[ 8557], 99.95th=[ 8926],
     | 99.99th=[ 9060]
   bw (  KiB/s): min= 2043, max=413696, per=16.32%, avg=69517.25, stdev=52671.70, samples=747
   iops        : min=    1, max=  404, avg=67.81, stdev=51.44, samples=747
  lat (msec)   : 10=0.11%, 20=0.20%, 50=1.06%, 100=2.09%, 250=7.54%
  lat (msec)   : 500=9.57%, 750=9.37%, 1000=17.95%
  cpu          : usr=0.40%, sys=1.02%, ctx=24563, majf=0, minf=8
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.2%, 16=0.5%, 32=1.0%, >=64=98.1%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=0,25871,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
  WRITE: bw=416MiB/s (436MB/s), 416MiB/s-416MiB/s (436MB/s-436MB/s), io=25.3GiB (27.1GB), run=62182-62182msec
```

### ssd write throughput
> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 64 -thread -rw=write -ioengine=libaio -bs=1M -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
Jobs: 1 (f=1): [_(1),W(1),_(6)][13.0%][r=0KiB/s,w=126MiB/s][r=0,w=126 IOPS][eta 07m:08s]
mytest: (groupid=0, jobs=8): err= 0: pid=3510205: Thu Jan 28 12:03:45 2021
  write: IOPS=404, BW=405MiB/s (424MB/s)(25.3GiB/64016msec)
    slat (usec): min=102, max=780, avg=249.56, stdev=47.69
    clat (msec): min=5, max=4627, avg=1207.10, stdev=482.78
     lat (msec): min=5, max=4627, avg=1207.35, stdev=482.78
    clat percentiles (msec):
     |  1.00th=[   92],  5.00th=[  380], 10.00th=[  625], 20.00th=[  902],
     | 30.00th=[ 1099], 40.00th=[ 1183], 50.00th=[ 1234], 60.00th=[ 1284],
     | 70.00th=[ 1351], 80.00th=[ 1435], 90.00th=[ 1636], 95.00th=[ 1804],
     | 99.00th=[ 2735], 99.50th=[ 3742], 99.90th=[ 4144], 99.95th=[ 4396],
     | 99.99th=[ 4597]
   bw (  KiB/s): min= 1777, max=280576, per=16.52%, avg=68435.18, stdev=43939.24, samples=760
   iops        : min=    1, max=  274, avg=66.77, stdev=42.91, samples=760
  lat (msec)   : 10=0.04%, 20=0.07%, 50=0.30%, 100=0.81%, 250=1.84%
  lat (msec)   : 500=3.52%, 750=8.76%, 1000=8.37%
  cpu          : usr=0.41%, sys=0.98%, ctx=26071, majf=0, minf=8
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.2%, 16=0.5%, 32=1.0%, >=64=98.1%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=0,25905,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
  WRITE: bw=405MiB/s (424MB/s), 405MiB/s-405MiB/s (424MB/s-424MB/s), io=25.3GiB (27.2GB), run=64016-64016msec
```

### ssd read throughput
> fio -filename=/mapr/my.cluster.com/ssd/s1 -direct=1 -iodepth 64 -thread -rw=read -ioengine=libaio -bs=1M -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=8): err= 0: pid=3531753: Thu Jan 28 12:07:29 2021
   read: IOPS=811, BW=811MiB/s (851MB/s)(48.0GiB/60598msec)
    slat (usec): min=60, max=3759, avg=179.36, stdev=56.91
    clat (msec): min=2, max=2114, avg=629.40, stdev=320.15
     lat (msec): min=2, max=2114, avg=629.58, stdev=320.15
    clat percentiles (msec):
     |  1.00th=[   17],  5.00th=[   93], 10.00th=[  140], 20.00th=[  296],
     | 30.00th=[  443], 40.00th=[  617], 50.00th=[  709], 60.00th=[  726],
     | 70.00th=[  760], 80.00th=[  885], 90.00th=[ 1028], 95.00th=[ 1133],
     | 99.00th=[ 1334], 99.50th=[ 1452], 99.90th=[ 1754], 99.95th=[ 1821],
     | 99.99th=[ 2022]
   bw (  KiB/s): min= 2035, max=544768, per=12.77%, avg=106095.02, stdev=72490.95, samples=939
   iops        : min=    1, max=  532, avg=103.56, stdev=70.80, samples=939
  lat (msec)   : 4=0.07%, 10=0.44%, 20=0.67%, 50=1.66%, 100=2.78%
  lat (msec)   : 250=11.01%, 500=17.40%, 750=34.58%, 1000=19.62%
  cpu          : usr=0.13%, sys=1.86%, ctx=49360, majf=0, minf=789
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.3%, 32=0.5%, >=64=99.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=49161,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
   READ: bw=811MiB/s (851MB/s), 811MiB/s-811MiB/s (851MB/s-851MB/s), io=48.0GiB (51.5GB), run=60598-60598msec
```

### hdd read throughput

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 64 -thread -rw=read -ioengine=libaio -bs=1M -size=1T -numjobs=8 -runtime=60 -group_reporting -name=mytest

```
Jobs: 8 (f=8): [R(8)][100.0%][r=812MiB/s,w=0KiB/s][r=812,w=0 IOPS][eta 00m:00s]
mytest: (groupid=0, jobs=8): err= 0: pid=3486132: Thu Jan 28 11:58:26 2021
   read: IOPS=805, BW=806MiB/s (845MB/s)(47.7GiB/60553msec)
    slat (usec): min=70, max=4425, avg=180.51, stdev=60.74
    clat (usec): min=1921, max=1862.8k, avg=634005.91, stdev=372110.00
     lat (msec): min=2, max=1862, avg=634.19, stdev=372.11
    clat percentiles (msec):
     |  1.00th=[   16],  5.00th=[   62], 10.00th=[  107], 20.00th=[  167],
     | 30.00th=[  292], 40.00th=[  684], 50.00th=[  743], 60.00th=[  810],
     | 70.00th=[  885], 80.00th=[  978], 90.00th=[ 1062], 95.00th=[ 1116],
     | 99.00th=[ 1284], 99.50th=[ 1351], 99.90th=[ 1670], 99.95th=[ 1703],
     | 99.99th=[ 1787]
   bw (  KiB/s): min= 2019, max=540672, per=12.98%, avg=107107.33, stdev=91026.66, samples=923
   iops        : min=    1, max=  528, avg=104.54, stdev=88.91, samples=923
  lat (msec)   : 2=0.01%, 4=0.10%, 10=0.48%, 20=0.71%, 50=2.57%
  lat (msec)   : 100=5.64%, 250=16.91%, 500=9.43%, 750=17.08%, 1000=29.44%
  cpu          : usr=0.13%, sys=1.84%, ctx=48721, majf=0, minf=2316
  IO depths    : 1=0.1%, 2=0.1%, 4=0.1%, 8=0.1%, 16=0.3%, 32=0.5%, >=64=99.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.1%, >=64=0.0%
     issued rwts: total=48798,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=64

Run status group 0 (all jobs):
   READ: bw=806MiB/s (845MB/s), 806MiB/s-806MiB/s (845MB/s-845MB/s), io=47.7GiB (51.2GB), run=60553-60553msec
```


## Write

### 4node hdd write Block=>8k nfs-client=>1

> fio -filename=/mapr/my.cluster.com/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=1000 -group_reporting -name=mytest

```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
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



