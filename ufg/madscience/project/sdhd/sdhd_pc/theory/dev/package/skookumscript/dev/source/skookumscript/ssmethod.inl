// File Line: 38
// RVA: 0x105FF0
void __fastcall SSMethodFunc::SSMethodFunc(SSMethodFunc *this, ASymbol *name, SSClass *scope_p, SSParameters *params_p, void (__fastcall *atomic_f)(SSInvokedMethod *, SSInstance **))
{
  this->i_name = (ASymbol)name->i_uid;
  this->i_scope_p = scope_p;
  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable';
  this->i_params_p.i_obj_p = params_p;
  if ( params_p )
    ++params_p->i_ref_count;
  this->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable';
  this->vfptr = (SSInvokableBaseVtbl *)&SSMethodFunc::`vftable';
  this->i_atomic_f = atomic_f;
}

