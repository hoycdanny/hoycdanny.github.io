$Id: ReadMe.txt 2179 2013-05-28 22:16:51Z mesnierp $

The IFR was returning incorrect results for enums:

For m1::c2 the TAO_IFR function type()->kind() of CORBA::ConstantDef was returning 0
instead of the value "tk_enum" and then wasn't handling the value of such a constant.
