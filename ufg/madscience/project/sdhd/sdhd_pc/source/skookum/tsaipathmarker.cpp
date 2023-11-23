// File Line: 57
// RVA: 0x4FB750
void __fastcall UFG::TSAIPathMarker::Mthd_get_arrival_tolerance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::AIMarker *vfptr; // rcx
  float ArrivalTolerance; // xmm0_4

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::AIMarker *)i_obj_p[2].vfptr;
    if ( vfptr )
      ArrivalTolerance = UFG::AIMarker::GetArrivalTolerance(vfptr, vfptr->m_pSimObject);
    else
      ArrivalTolerance = FLOAT_N1_0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(ArrivalTolerance));
  }
}

// File Line: 66
// RVA: 0x4FEB30
void __fastcall UFG::TSAIPathMarker::Mthd_get_speed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::AIMarker *vfptr; // rcx
  UFG::qSymbol *Speed; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol v7; // [rsp+50h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::AIMarker *)i_obj_p[2].vfptr;
    if ( vfptr )
      Speed = UFG::AIMarker::GetSpeed(vfptr, &result, vfptr->m_pSimObject);
    else
      Speed = UFG::qSymbol::create_from_string(&v7, "eMoveType_None");
    *ppResult = SSSymbol::as_instance((ASymbol *)Speed);
  }
}

