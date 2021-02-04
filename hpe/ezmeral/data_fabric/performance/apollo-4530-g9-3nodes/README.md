# Apollo 4530 Gen9 Data Fabric Performance

## 測試環境介紹


Apollo 4530 Gen9 *3
```
Node 1
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable

Node 2
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable

Node 3
2* CPU E5-2660 v4 @ 2.00GHz 14 core
1* Memory 256G 
2* Boot SSD  VK000480GWJPE 
15* 7.2K HDD 6TB MB6000JVYZD
1* HPE Ethernet 10Gb 2-port 562FLR-SFP+ Adpt
1* 10G Cable
```

Data Disk
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
|     HDD|      8k|       1|         1|     psync|       1TB|       100|    Random|  132MiB/s|    16.9k|  33.1MiB/s|      4234|
|     HDD|    256k|       1|         1|     psync|       1TB|       100|    Random| 1671MiB/s|     6683|   485MiB/s|      1938|


IOPS Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
```

IOPS Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=8k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
```

Bandwidth Random Write Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randwrite -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
mytest: (groupid=0, jobs=100): err= 0: pid=2951: Thu Feb  4 12:43:56 2021
  write: IOPS=2109, BW=527MiB/s (553MB/s)(155GiB/300056msec)
    clat (msec): min=3, max=681, avg=46.08, stdev=39.95
     lat (msec): min=3, max=681, avg=46.09, stdev=39.95
    clat percentiles (msec):
     |  1.00th=[    5],  5.00th=[    6], 10.00th=[    7], 20.00th=[    8],
     | 30.00th=[   12], 40.00th=[   37], 50.00th=[   58], 60.00th=[   63],
     | 70.00th=[   66], 80.00th=[   69], 90.00th=[   72], 95.00th=[   78],
     | 99.00th=[  232], 99.50th=[  292], 99.90th=[  368], 99.95th=[  384],
     | 99.99th=[  418]
   bw (  KiB/s): min=  510, max=13312, per=1.03%, avg=5552.40, stdev=1872.08, samples=58359
   iops        : min=    1, max=   52, avg=21.63, stdev= 7.32, samples=58359
  lat (msec)   : 4=0.09%, 10=27.57%, 20=9.18%, 50=6.70%, 100=54.20%
  lat (msec)   : 250=1.40%, 500=0.86%, 750=0.01%
  cpu          : usr=0.05%, sys=0.14%, ctx=644791, majf=0, minf=16670
  IO depths    : 1=100.0%, 2=0.0%, 4=0.0%, 8=0.0%, 16=0.0%, 32=0.0%, >=64=0.0%
     submit    : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     complete  : 0=0.0%, 4=100.0%, 8=0.0%, 16=0.0%, 32=0.0%, 64=0.0%, >=64=0.0%
     issued rwts: total=0,633071,0,0 short=0,0,0,0 dropped=0,0,0,0
     latency   : target=0, window=0, percentile=100.00%, depth=1

Run status group 0 (all jobs):
  WRITE: bw=527MiB/s (553MB/s), 527MiB/s-527MiB/s (553MB/s-553MB/s), io=155GiB (166GB), run=300056-300056msec
```

Bandwidth Random Read Test

> fio -filename=/nfs/hdd/h1 -direct=1 -iodepth 1 -thread -rw=randread -ioengine=psync -bs=256k -size=1T -numjobs=100 -runtime=300 -group_reporting -name=mytest

```
```
