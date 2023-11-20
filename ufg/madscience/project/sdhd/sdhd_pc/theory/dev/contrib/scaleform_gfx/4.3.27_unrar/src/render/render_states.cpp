// File Line: 24
// RVA: 0x159CDE0
__int64 Scaleform::Render::_dynamic_initializer_for__StateNone_InterfaceImpl__()
{
  StateType_Interfaces[0] = (Scaleform::Render::StateData::Interface *)&Scaleform::Render::StateNone_InterfaceImpl;
  Scaleform::Render::StateNone_InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_Value::`vftable';
  return atexit(Scaleform::Render::_dynamic_atexit_destructor_for__StateNone_InterfaceImpl__);
}

// File Line: 33
// RVA: 0x159C920
__int64 dynamic_initializer_for__Scaleform::Render::BlendState::InterfaceImpl__()
{
  qword_142451A48 = (__int64)&Scaleform::Render::BlendState::InterfaceImpl;
  Scaleform::Render::BlendState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_Value::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::BlendState::InterfaceImpl__);
}

// File Line: 36
// RVA: 0x997EC0
bool __fastcall Scaleform::Render::BlendState::IsTargetAllocationNeededForBlendMode(Scaleform::Render::BlendMode mode)
{
  signed int v1; // eax
  bool result; // al

  result = 0;
  if ( (unsigned int)mode <= 0xE )
  {
    v1 = 24804;
    if ( _bittest(&v1, mode) )
      result = 1;
  }
  return result;
}

// File Line: 58
// RVA: 0x159CAE0
__int64 dynamic_initializer_for__Scaleform::Render::Scale9State::InterfaceImpl__()
{
  qword_142451A50 = (__int64)&Scaleform::Render::Scale9State::InterfaceImpl;
  Scaleform::Render::Scale9State::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::Scale9State::InterfaceImpl__);
}

// File Line: 61
// RVA: 0x159CB60
__int64 dynamic_initializer_for__Scaleform::Render::ViewMatrix3DState::InterfaceImpl__()
{
  qword_142451A68 = (__int64)&Scaleform::Render::ViewMatrix3DState::InterfaceImpl;
  Scaleform::Render::ViewMatrix3DState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::ViewMatrix3DState::InterfaceImpl__);
}

// File Line: 64
// RVA: 0x159CAA0
__int64 dynamic_initializer_for__Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl__()
{
  qword_142451A70 = (__int64)&Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl;
  Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl__);
}

// File Line: 67
// RVA: 0x159CB20
__int64 dynamic_initializer_for__Scaleform::Render::UserDataState::InterfaceImpl__()
{
  qword_142451A78 = (__int64)&Scaleform::Render::UserDataState::InterfaceImpl;
  Scaleform::Render::UserDataState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::UserDataState::InterfaceImpl__);
}

// File Line: 81
// RVA: 0x159CA60
__int64 dynamic_initializer_for__Scaleform::Render::OrigScale9ParentState::InterfaceImpl__()
{
  qword_142451A80 = (__int64)&Scaleform::Render::OrigScale9ParentState::InterfaceImpl;
  Scaleform::Render::OrigScale9ParentState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::OrigScale9ParentState::Interface::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::OrigScale9ParentState::InterfaceImpl__);
}

// File Line: 84
// RVA: 0x159C9E0
__int64 dynamic_initializer_for__Scaleform::Render::MaskNodeState::InterfaceImpl__()
{
  qword_142451A60 = (__int64)&Scaleform::Render::MaskNodeState::InterfaceImpl;
  Scaleform::Render::MaskNodeState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::MaskNodeState::Interface::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::MaskNodeState::InterfaceImpl__);
}

// File Line: 87
// RVA: 0x9548B0
void __fastcall Scaleform::Render::OrigScale9ParentState::Interface::AddRef(Scaleform::Render::OrigScale9ParentState::Interface *this, void *data, Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  if ( b != 1 )
    ++*((_QWORD *)data + 1);
}

// File Line: 92
// RVA: 0x9A7940
void __fastcall Scaleform::Render::MaskNodeState::Interface::Release(Scaleform::Render::OrigScale9ParentState::Interface *this, void *data, Scaleform::Render::StateData::Interface::RefBehaviour b)
{
  bool v3; // zf

  if ( b != 1 )
  {
    v3 = (*((_QWORD *)data + 1))-- == 1i64;
    if ( v3 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)data);
  }
}

// File Line: 98
// RVA: 0x159C9A0
__int64 dynamic_initializer_for__Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl__()
{
  qword_142451A88 = (__int64)&Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl;
  Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_Value::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl__);
}

// File Line: 102
// RVA: 0x159C960
__int64 dynamic_initializer_for__Scaleform::Render::FilterState::InterfaceImpl__()
{
  qword_142451A58 = (__int64)&Scaleform::Render::FilterState::InterfaceImpl;
  Scaleform::Render::FilterState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::FilterState::InterfaceImpl__);
}

// File Line: 105
// RVA: 0x159CA20
__int64 dynamic_initializer_for__Scaleform::Render::OrigNodeBoundsState::InterfaceImpl__()
{
  qword_142451A90 = (__int64)&Scaleform::Render::OrigNodeBoundsState::InterfaceImpl;
  Scaleform::Render::OrigNodeBoundsState::InterfaceImpl.vfptr = (Scaleform::Render::StateData::InterfaceVtbl *)&Scaleform::Render::StateData::Interface_RefCountImpl::`vftable';
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::OrigNodeBoundsState::InterfaceImpl__);
}

