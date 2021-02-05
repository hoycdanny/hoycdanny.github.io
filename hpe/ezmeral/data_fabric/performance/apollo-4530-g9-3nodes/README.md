# Apollo 4530 Gen9 Data Fabric Performance

## 測試環境介紹


Apollo 4530 Gen9 *3
```
MapR Node 1
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable

MapR Node 2
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable

MapR Node 3
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable

Test Node
2* CPU Silver 4110 CPU @ 2.10GHz 8 core
8* Memory 16G 
2* Boot 1.92GB MK001920GWCFB [RAID 0]
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
```

MapR Data Disk
```
Specifications
Brand: HPE
MPN: MB6000JVYZD-SC

Option Part Number: 861754-B21
Spare Part Number: 862140-001
Model Number: MB6000JVYZD
Assembly Number: 846521-002
HPE GPN: 861759-006

Performance
Transfer Rate Synchronous (Max): 12 Gb/sec
Rotational Speed: 7200 rpm
OD Media Rate, Max Sequential Throughput (MiB/s): 200
128Kib Random Rd (IOPs): 100
128Kib Random 70% RD/ 30% WT (IOPs): 105
128Kib Random 50% RD/ 50% WT (IOPs): 110

https://www.storagepartsdirect.com/hpe-mb6000jvyzd-sc-6tb-7200rpm-3-5in-ds-sas-12g-midline-g9-g10-hdd/
```



## 測試總結

|    Type|   Block|  Direct|   iodepth|  ioengine|      size|   numjobs|        rw|      Read|Read/IOPS|      Write|Write/IOPS|
|:------:|-------:|-------:|---------:|:--------:|---------:|---------:|:--------:|---------:|--------:|----------:|---------:|
|     HDD|      8k|       1|         1|     psync|       1TB|       100|    Random| 46.9MiB/s|     6004|   101MiB/s|      12.9|
|     HDD|    256k|       1|         1|     psync|       1TB|       100|    Random|  844MiB/s|     3376|   771MiB/s|      3085|


IOPS Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=100): err= 0: pid=6829: Fri Feb  5 13:10:14 2021
  write: IOPS=6004, BW=46.9MiB/s (49.2MB/s)(13.7GiB/300018msec)
    clat (usec): min=1820, max=1742.8k, avg=16324.80, stdev=35076.15
     lat (usec): min=1820, max=1742.8k, avg=16325.18, stdev=35076.17
    clat percentiles (msec):
     |  1.00th=[    3],  5.00th=[    5], 10.00th=[    5], 20.00th=[    6],
     | 30.00th=[    7], 40.00th=[    8], 50.00th=[    9], 60.00th=[   10],
     | 70.00th=[   12], 80.00th=[   14], 90.00th=[   23], 95.00th=[   56],
     | 99.00th=[  174], 99.50th=[  230], 99.90th=[  422], 99.95th=[  527],
     | 99.99th=[  802]
   bw (  KiB/s): min=   15, max= 1600, per=1.03%, avg=492.74, stdev=222.88, samples=58455
   iops        : min=    1, max=  200, avg=61.55, stdev=27.86, samples=58455
  lat (msec)   : 2=0.01%, 4=4.18%, 10=57.27%, 20=27.35%, 50=5.71%
  lat (msec)   : 100=2.89%, 250=2.20%, 500=0.34%, 750=0.05%, 1000=0.01%
  cpu          : usr=0.04%, sys=0.13%, ctx=1821311, majf=0, minf=1040
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,1801383,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=46.9MiB/s (49.2MB/s), 46.9MiB/s-46.9MiB/s (49.2MB/s-49.2MB/s), io=13.7GiB (14.8GB), run=300018-300018msec
```

IOPS Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=100): err= 0: pid=2894: Fri Feb  5 13:29:03 2021
   read: IOPS=12.9k, BW=101MiB/s (106MB/s)(29.5GiB/300041msec)
    clat (usec): min=145, max=348491, avg=7748.72, stdev=5363.40
     lat (usec): min=145, max=348491, avg=7748.85, stdev=5363.41
    clat percentiles (msec):
     |  1.00th=[    3],  5.00th=[    4], 10.00th=[    5], 20.00th=[    5],
     | 30.00th=[    6], 40.00th=[    6], 50.00th=[    7], 60.00th=[    8],
     | 70.00th=[    9], 80.00th=[   10], 90.00th=[   12], 95.00th=[   16],
     | 99.00th=[   28], 99.50th=[   36], 99.90th=[   66], 99.95th=[   82],
     | 99.99th=[  128]
   bw (  KiB/s): min=  352, max= 2080, per=1.00%, avg=1031.93, stdev=164.26, samples=59944
   iops        : min=   44, max=  260, avg=128.95, stdev=20.54, samples=59944
  lat (usec)   : 250=0.01%, 500=0.01%, 750=0.05%, 1000=0.07%
  lat (msec)   : 2=0.42%, 4=5.78%, 10=79.15%, 20=12.26%, 50=2.05%
  lat (msec)   : 100=0.19%, 250=0.02%, 500=0.01%
  cpu          : usr=0.05%, sys=0.20%, ctx=3904109, majf=0, minf=2161
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=3870164,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=101MiB/s (106MB/s), 101MiB/s-101MiB/s (106MB/s-106MB/s), io=29.5GiB (31.7GB), run=300041-300041msec
```

Bandwidth Random Write Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=100): err= 0: pid=6512: Fri Feb  5 13:01:57 2021
  write: IOPS=3085, BW=771MiB/s (809MB/s)(226GiB/300056msec)
    clat (msec): min=3, max=257, avg=32.36, stdev=19.58
     lat (msec): min=3, max=257, avg=32.38, stdev=19.58
    clat percentiles (msec):
     |  1.00th=[    7],  5.00th=[    9], 10.00th=[   11], 20.00th=[   15],
     | 30.00th=[   20], 40.00th=[   25], 50.00th=[   30], 60.00th=[   34],
     | 70.00th=[   39], 80.00th=[   47], 90.00th=[   62], 95.00th=[   71],
     | 99.00th=[   87], 99.50th=[   93], 99.90th=[  108], 99.95th=[  122],
     | 99.99th=[  228]
   bw (  KiB/s): min=  512, max=16896, per=1.00%, avg=7900.46, stdev=1304.10, samples=59963
   iops        : min=    2, max=   66, avg=30.82, stdev= 5.10, samples=59963
  lat (msec)   : 4=0.01%, 10=9.14%, 20=22.10%, 50=51.05%, 100=17.50%
  lat (msec)   : 250=0.20%, 500=0.01%
  cpu          : usr=0.07%, sys=0.22%, ctx=940746, majf=0, minf=47798
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,925715,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=771MiB/s (809MB/s), 771MiB/s-771MiB/s (809MB/s-809MB/s), io=226GiB (243GB), run=300056-300056msec
```

Bandwidth Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=100): err= 0: pid=6353: Fri Feb  5 12:54:25 2021
   read: IOPS=3376, BW=844MiB/s (885MB/s)(247GiB/300072msec)
    clat (usec): min=972, max=881455, avg=29608.50, stdev=32686.46
     lat (usec): min=972, max=881455, avg=29608.70, stdev=32686.47
    clat percentiles (usec):
     |  1.00th=[  1991],  5.00th=[  5473], 10.00th=[  7439], 20.00th=[ 10159],
     | 30.00th=[ 12518], 40.00th=[ 15139], 50.00th=[ 19268], 60.00th=[ 22414],
     | 70.00th=[ 29492], 80.00th=[ 41157], 90.00th=[ 64226], 95.00th=[ 92799],
     | 99.00th=[175113], 99.50th=[202376], 99.90th=[261096], 99.95th=[304088],
     | 99.99th=[413139]
   bw (  KiB/s): min=  512, max=20480, per=1.00%, avg=8644.77, stdev=2647.28, samples=59989
   iops        : min=    2, max=   80, avg=33.72, stdev=10.34, samples=59989
  lat (usec)   : 1000=0.01%
  lat (msec)   : 2=1.03%, 4=2.66%, 10=15.81%, 20=32.42%, 50=32.98%
  lat (msec)   : 100=10.90%, 250=4.08%, 500=0.12%, 750=0.01%, 1000=0.01%
  cpu          : usr=0.02%, sys=0.16%, ctx=1036790, majf=0, minf=14724
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=1013129,0,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
   READ: bw=844MiB/s (885MB/s), 844MiB/s-844MiB/s (885MB/s-885MB/s), io=247GiB (266GB), run=300072-300072msec
```
