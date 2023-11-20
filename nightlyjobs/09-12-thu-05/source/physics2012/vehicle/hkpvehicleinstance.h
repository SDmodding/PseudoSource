// File Line: 339
// RVA: 0xE25970
void __fastcall hkpVehicleInstance::hkpVehicleInstance(hkpVehicleInstance *this, hkFinishLoadedObjectFlag f)
{
  hkpVehicleInstance *v2; // rbx
  hkStringPtr *v3; // rcx
  _QWORD **v4; // rax
  hkpVehicleDefaultSimulation *v5; // rax
  hkpVehicleSimulation *v6; // rax
  hkpVehicleSimulation *v7; // rcx
  int v8; // [rsp+38h] [rbp+10h]

  v8 = f.m_finishing;
  v2 = this;
  v3 = &this->m_name;
  v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
  hkStringPtr::hkStringPtr(v3, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  if ( v8 && !v2->m_vehicleSimulation )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                          v4[11],
                                          96i64);
    if ( v5 )
    {
      hkpVehicleDefaultSimulation::hkpVehicleDefaultSimulation(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v2->m_vehicleSimulation = v7;
    ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *))v7->vfptr[1].__first_virtual_table_function__)(
      v7,
      v2);
  }
}

