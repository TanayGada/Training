## Storage on AWS EC2 
- Blocks/Disks are used for storage in normal PC
- Volumnes are used for storage in AWS EC2
- EBS(Elastic Block Storage) allows us to create Volumes
- After creating volumes using EBS, we attach those volumes to EC2 instance

### 1. lsblk
- list blocks/volumns attached to EC2
- root volume is named `xvda`

### 2. df -h
- shows space available in volume


### 3. mounting
- to use the new attached volumne, we need to mount it to linux

### 4. attaching
- after creating volume using EBS, we need to attach it to EC2 instance.
- sda, sdb, ..., sde are used by root volume.
- we can use name from sdf, sdg, ...

## Physical Volumn, Volumn group, Logical Volumn
- Physical Volumn creates a volumne group
- Logical Volumns are created using Volumn group which are flexible

## LVM
- Logical Volumn Manager manages the PV, VG, LV

### pvs
- shows physical volumes

### lsblk
- shows volumnes/disks/blocks

### pvcreate /dev/xvdf /dev/xvdg /dev/xvdh
- creates physical volumns

### vgcreate volume_grp_name /dev/xvdf /dev/xvdg
- create volume group using PV

### vgs
- list Volume Group

### lvcreate -L 10GB -n logical_volume_name
- create logical volume of size 10GB

### extend existing logical volume
- `lvextend -L +5G lv_path`

### pvdisplay
- shows details of PV

### vgdisplay
- shows details of VG

### lvdisplay
- shows details of LV

### lvs
- list Logical Volume

## Mounting
### 1. need a directory which will be mount point
- `mkdir mnt/logical_volume_mount`

### 2. format the logical volume
- `mkfs.ext4 /dev/volume_grp/logical_volume`

### 3. mount logical volume to directory
- `mount /dev/volume_grp/logical_volume mnt/logical_volume_mount`

### 4. unmount LV
- `unmount mnt/logical_volume_mount`
- data is not lost, just it is not usable after unmounting


## we can mount logical volume or directly the physical volume
1. `mkdir mnt/physical_disk_mount`
2. `mkfs -t ext4 /dev/xvdf`
3. `mount /dev/xvdf /mnt/physical_disk_mount/`