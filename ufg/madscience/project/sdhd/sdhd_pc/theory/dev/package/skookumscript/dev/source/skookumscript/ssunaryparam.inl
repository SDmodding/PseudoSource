// File Line: 56
// RVA: 0x106600
void __fastcall SSUnaryParam::SSUnaryParam(SSUnaryParam *this, SSUnaryParam *uparam_p)
{
  SSUnaryParam *v2; // rbx
  SSUnaryParam *v3; // rsi
  SSClassDescBase *v4; // rcx
  SSClass *v5; // rdi
  SSClassDescBase *v6; // rcx

  v2 = uparam_p;
  v3 = this;
  this->i_name.i_uid = uparam_p->i_name.i_uid;
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
  this->vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  this->i_type_p.i_obj_p = uparam_p->i_type_p.i_obj_p;
  v4 = uparam_p->i_type_p.i_obj_p;
  if ( v4 )
    (*(void (__cdecl **)(SSClassDescBase *))v4->vfptr->gap8)(v4);
  v3->i_default_p = v2->i_default_p;
  v5 = SSBrain::c_object_class_p;
  if ( (SSClass *)v2->i_type_p.i_obj_p != SSBrain::c_object_class_p )
  {
    if ( SSBrain::c_object_class_p )
      (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
    v6 = v2->i_type_p.i_obj_p;
    if ( v6 )
      (*(void (__cdecl **)(SSClassDescBase *))&v6->vfptr->gap8[8])(v6);
    v2->i_type_p.i_obj_p = (SSClassDescBase *)&v5->vfptr;
  }
  v2->i_default_p = 0i64;
}

// File Line: 66
// RVA: 0x112680
bool __fastcall SSUnaryParam::compare_equal(SSUnaryParam *this, SSParameterBase *param)
{
  SSParameterBase *v2; // rdi
  SSUnaryParam *v3; // rbx

  v2 = param;
  v3 = this;
  return this->i_name.i_uid == param->i_name.i_uid
      && ((unsigned int (*)(void))this->vfptr->get_kind)() != 3
      && v3->i_type_p.i_obj_p == (SSClassDescBase *)v2[1].vfptr;
}

// File Line: 80
// RVA: 0x1127A0
bool __fastcall SSUnaryParam::compare_less(SSUnaryParam *this, SSParameterBase *param)
{
  unsigned int v2; // eax
  SSClassDescBase **v3; // rbx
  unsigned int v4; // edx
  SSUnaryParam *v5; // rdi

  v2 = this->i_name.i_uid;
  v3 = (SSClassDescBase **)param;
  v4 = param->i_name.i_uid;
  v5 = this;
  return v2 < v4
      || v2 == v4
      && (((unsigned int (__fastcall *)(SSClassDescBase **))(*v3)[4].vfptr)(v3) == 3
       || SSClassDescBase::compare(v5->i_type_p.i_obj_p, v3[2], (__int64)v3) == -1);
}

