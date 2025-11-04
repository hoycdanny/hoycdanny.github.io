# $Id: platform_vxworks6.7.GNU 2179 2013-05-28 22:16:51Z mesnierp $
# VxWorks 6.7

ifeq ($(VXWORKS_VERSION_FLAG),)
  VXWORKS_VERSION_FLAG = -DACE_VXWORKS=0x670
endif # VXWORKS_VERSION_FLAG

include $(ACE_ROOT)/include/makeinclude/platform_vxworks6.6.GNU
