// File Line: 339
// RVA: 0xE25970
void __fastcall hkpVehicleInstance::hkpVehicleInstance(hkpVehicleInstance *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr *p_m_name; // rcx
  _QWORD **Value; // rax
  hkpVehicleDefaultSimulation *v5; // rax
  hkpVehicleSimulation *v6; // rax
  hkpVehicleSimulation *v7; // rcx

  p_m_name = &this->m_name;
  p_m_name[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleInstance::`vftable;
  if ( f.m_finishing && !this->m_vehicleSimulation )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpVehicleDefaultSimulation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
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
    this->m_vehicleSimulation = v7;
    ((void (__fastcall *)(hkpVehicleSimulation *, hkpVehicleInstance *))v7->vfptr[1].__first_virtual_table_function__)(
      v7,
      this);
  }
}

