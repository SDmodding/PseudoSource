// File Line: 34
// RVA: 0x205750
void __fastcall UFG::Editor::TSDAGPath::BindAtomics(UFG::Editor::TSDAGPath *this)
{
  sDAGPathClass = SSBrain::get_class("DAGPath");
  SSClass::register_method_func(sDAGPathClass, &ASymbolX_ctor, UFG::Editor::TSDAGPath::Mthd_constructor, 0);
  SSClass::register_method_func(sDAGPathClass, &ASymbolX_dtor, UFG::Editor::TSDAGPath::Mthd_destructor, 0);
}

// File Line: 44
// RVA: 0x20DF80
void __fastcall UFG::Editor::TSDAGPath::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  char v3; // bl
  UFG::allocator::free_link *v4; // rsi
  UFG::qString *v5; // rax
  SSObjectBaseVtbl *v6; // rax
  SSObjectBaseVtbl *v7; // rdx
  SSObjectBase *v8; // rcx
  UFG::qString v9; // [rsp+30h] [rbp-38h]

  v2 = pScope;
  v3 = 0;
  v4 = UFG::qMalloc(0x58ui64, "Skookum.DAGPath", 0i64);
  if ( v4 )
  {
    UFG::qString::qString(&v9, *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
    v3 = 1;
    UFG::Editor::DAGPath::DAGPath((UFG::Editor::DAGPath *)v4, v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->i_scope_p.i_obj_p;
  if ( !v8 || v2->i_scope_p.i_ptr_id != v8->i_ptr_id )
    v8 = 0i64;
  v8[2].vfptr = v7;
  if ( v3 & 1 )
    UFG::qString::~qString(&v9);
}

// File Line: 52
// RVA: 0x20E040
void __fastcall UFG::Editor::TSDAGPath::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    UFG::Editor::DAGPath::~DAGPath((UFG::Editor::DAGPath *)v2[2].vfptr);
    operator delete[](v3);
  }
}

