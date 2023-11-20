// File Line: 34
// RVA: 0x9AD30
void __fastcall hkSmallArray<hkpEntityActivationListener *>::~hkSmallArray<hkpEntityActivationListener *>(hkSmallArray<hkpEntityListener *> *this)
{
  unsigned __int16 v1; // di
  hkpEntityListener **v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_capacityAndFlags;
  if ( (v1 & 0x8000u) == 0 )
  {
    v2 = this->m_data;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpEntityListener **, _QWORD))(*v3[11] + 16i64))(v3[11], v2, 8 * (v1 & 0x3FFFu));
  }
}

