// File Line: 34
// RVA: 0x9AD30
void __fastcall hkSmallArray<hkpEntityActivationListener *>::~hkSmallArray<hkpEntityActivationListener *>(
        hkSmallArray<hkpEntityListener *> *this)
{
  signed __int16 m_capacityAndFlags; // di
  hkpEntityListener **m_data; // rbx
  _QWORD **Value; // rax

  m_capacityAndFlags = this->m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
  {
    m_data = this->m_data;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntityListener **, _QWORD))(*Value[11] + 16i64))(
      Value[11],
      m_data,
      8 * (m_capacityAndFlags & 0x3FFFu));
  }
}

