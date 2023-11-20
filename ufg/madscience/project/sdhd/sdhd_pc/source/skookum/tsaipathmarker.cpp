// File Line: 57
// RVA: 0x4FB750
void __fastcall UFG::TSAIPathMarker::Mthd_get_arrival_tolerance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  UFG::AIMarker *v4; // rcx
  float v5; // xmm0_4

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (UFG::AIMarker *)v2[2].vfptr;
    if ( v4 )
      v5 = UFG::AIMarker::GetArrivalTolerance(v4, v4->m_pSimObject);
    else
      v5 = FLOAT_N1_0;
    *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v5));
  }
}

// File Line: 66
// RVA: 0x4FEB30
void __fastcall UFG::TSAIPathMarker::Mthd_get_speed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  UFG::AIMarker *v4; // rcx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]
  UFG::qSymbol v7; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (UFG::AIMarker *)v2[2].vfptr;
    if ( v4 )
      v5 = UFG::AIMarker::GetSpeed(v4, &result, v4->m_pSimObject);
    else
      v5 = UFG::qSymbol::create_from_string(&v7, "eMoveType_None");
    *v3 = SSSymbol::as_instance((ASymbol *)v5);
  }
}

