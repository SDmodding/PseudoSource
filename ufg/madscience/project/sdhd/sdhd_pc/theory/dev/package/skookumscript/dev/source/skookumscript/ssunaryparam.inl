// File Line: 56
// RVA: 0x106600
void __fastcall SSUnaryParam::SSUnaryParam(SSUnaryParam *this, SSUnaryParam *uparam_p)
{
  SSClassDescBase *i_obj_p; // rcx
  SSClass *v5; // rdi
  SSClassDescBase *v6; // rcx

  this->i_name.i_uid = uparam_p->i_name.i_uid;
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
  this->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  this->i_type_p.i_obj_p = uparam_p->i_type_p.i_obj_p;
  i_obj_p = uparam_p->i_type_p.i_obj_p;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))i_obj_p->vfptr->gap8)(i_obj_p);
  this->i_default_p = uparam_p->i_default_p;
  v5 = SSBrain::c_object_class_p;
  if ( uparam_p->i_type_p.i_obj_p != SSBrain::c_object_class_p )
  {
    if ( SSBrain::c_object_class_p )
      (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
    v6 = uparam_p->i_type_p.i_obj_p;
    if ( v6 )
      (*(void (__fastcall **)(SSClassDescBase *))&v6->vfptr->gap8[8])(v6);
    uparam_p->i_type_p.i_obj_p = v5;
  }
  uparam_p->i_default_p = 0i64;
}

// File Line: 66
// RVA: 0x112680
bool __fastcall SSUnaryParam::compare_equal(SSUnaryParam *this, SSParameterBase *param)
{
  return this->i_name.i_uid == param->i_name.i_uid
      && this->vfptr->get_kind(this) != SSParameter_group
      && this->i_type_p.i_obj_p == (SSClassDescBase *)param[1].vfptr;
}

// File Line: 80
// RVA: 0x1127A0
bool __fastcall SSUnaryParam::compare_less(SSUnaryParam *this, SSParameterBase *param)
{
  unsigned int i_uid; // eax
  unsigned int v4; // edx

  i_uid = this->i_name.i_uid;
  v4 = param->i_name.i_uid;
  return i_uid < v4
      || i_uid == v4
      && (param->vfptr->get_kind(param) == SSParameter_group
       || SSClassDescBase::compare(this->i_type_p.i_obj_p, (SSClassDescBase *)param[1].vfptr) == -1);
}

