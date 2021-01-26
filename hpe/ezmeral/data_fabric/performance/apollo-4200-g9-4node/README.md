# Apollo 4200 Gen9 Data Fabric Performance

## 測試環境介紹


Apollo 4200 Gen9 *4
```
1* CPU E5-2620 v4 @ 2.10GHz 
1* Memory 64G 
3* RI   SSD  VK000960GWSRT
9* 7.2K HDD  MB010000GWAYN
1* Mellanox Technologies MT27520 40G
```

## 寫入測試

### 4node hdd write Block=>8k

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

### 4node hdd write Block=>256k 

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
