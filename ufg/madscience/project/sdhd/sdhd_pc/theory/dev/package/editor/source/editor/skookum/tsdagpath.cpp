// File Line: 34
// RVA: 0x205750
void __fastcall UFG::Editor::TSDAGPath::BindAtomics(UFG::Editor::TSDAGPath *this)
{
  sDAGPathClass = SSBrain::get_class("DAGPath");
  SSClass::register_method_func(
    sDAGPathClass,
    &ASymbolX_ctor,
    UFG::Editor::TSDAGPath::Mthd_constructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    sDAGPathClass,
    &ASymbolX_dtor,
    UFG::Editor::TSDAGPath::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
}

// File Line: 44
// RVA: 0x20DF80
void __fastcall UFG::Editor::TSDAGPath::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v3; // bl
  UFG::allocator::free_link *v4; // rsi
  UFG::qString *v5; // rax
  SSObjectBaseVtbl *v6; // rax
  SSObjectBaseVtbl *v7; // rdx
  SSObjectBase *i_obj_p; // rcx
  UFG::qString v9; // [rsp+30h] [rbp-38h] BYREF

  v3 = 0;
  v4 = UFG::qMalloc(0x58ui64, "Skookum.DAGPath", 0i64);
  if ( v4 )
  {
    UFG::qString::qString(&v9, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v3 = 1;
    UFG::Editor::DAGPath::DAGPath((UFG::Editor::DAGPath *)v4, v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_obj_p[2].vfptr = v7;
  if ( (v3 & 1) != 0 )
    UFG::qString::~qString(&v9);
}

// File Line: 52
// RVA: 0x20E040
void __fastcall UFG::Editor::TSDAGPath::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rbx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)i_obj_p[2].vfptr);
    operator delete[](vfptr);
  }
}

