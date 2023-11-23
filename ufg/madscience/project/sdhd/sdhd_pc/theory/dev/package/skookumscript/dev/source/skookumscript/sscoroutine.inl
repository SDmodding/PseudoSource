// File Line: 74
// RVA: 0x104E40
void __fastcall SSCoroutineFunc::SSCoroutineFunc(
        SSCoroutineFunc *this,
        ASymbol *name,
        SSClass *scope_p,
        SSParameters *params_p,
        bool (__fastcall *update_f)(SSInvokedCoroutine *))
{
  this->i_name = (ASymbol)name->i_uid;
  this->i_scope_p = scope_p;
  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = params_p;
  if ( params_p )
    ++params_p->i_ref_count;
  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineBase::`vftable;
  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineFunc::`vftable;
  this->i_update_f = update_f;
}

