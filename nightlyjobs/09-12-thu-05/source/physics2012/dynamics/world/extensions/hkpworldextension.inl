// File Line: 35
// RVA: 0xD5E380
void __fastcall hkpWorldExtension::requireExtension<hkpCollisionCallbackUtil>(hkpWorldExtension *this, hkpWorld *world)
{
  hkpWorldExtension *WorldExtension; // rax
  _QWORD **Value; // rax
  hkpWorldExtension *v5; // rax
  hkpWorldExtension *v6; // rbx

  WorldExtension = hkpWorld::findWorldExtension((hkpWorld *)this, 1001);
  if ( WorldExtension )
  {
    ++WorldExtension->m_attachmentCount;
  }
  else
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpWorldExtension *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 120i64);
    v6 = v5;
    if ( v5 )
    {
      hkpWorldExtension::hkpWorldExtension(v5, 1001);
      v6->vfptr = (hkBaseObjectVtbl *)&hkpCollisionCallbackUtil::`vftable{for `hkpWorldExtension};
      v6[1].vfptr = (hkBaseObjectVtbl *)&hkpCollisionCallbackUtil::`vftable{for `hkpConstraintListener};
      hkpEndOfStepCallbackUtil::hkpEndOfStepCallbackUtil((hkpEndOfStepCallbackUtil *)&v6[1].m_memSizeAndFlags);
    }
    else
    {
      v6 = 0i64;
    }
    hkpWorld::addWorldExtension((hkpWorld *)this, v6);
    hkReferencedObject::removeReference(v6);
    ++v6->m_attachmentCount;
  }
}

// File Line: 48
// RVA: 0xE1BB60
void __fastcall hkpWorldExtension::releaseExtension<hkpCollisionCallbackUtil>(hkpWorldExtension *this, hkpWorld *world)
{
  hkpWorldExtension *WorldExtension; // rax

  WorldExtension = hkpWorld::findWorldExtension((hkpWorld *)this, 1001);
  if ( WorldExtension->m_attachmentCount-- == 1 )
    hkpWorld::removeWorldExtension((hkpWorld *)this, WorldExtension);
}

