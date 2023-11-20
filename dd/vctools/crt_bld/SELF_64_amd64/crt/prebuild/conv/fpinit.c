// File Line: 72
// RVA: 0x12ADCCC
void __fastcall fpmath(int initPrecision)
{
  cfltcvt_init(initPrecision);
}

// File Line: 98
// RVA: 0x12ADCD4
void (__fastcall *cfltcvt_init())(char *buffer, localeinfo_struct *_Locale)
{
  void (__fastcall *result)(char *, localeinfo_struct *); // rax

  off_142125658[0] = (void (__fastcall __noreturn *)())cropzeros;
  cfltcvt_tab[0] = (void (__fastcall *)())cfltcvt;
  off_142125660[0] = (void (__fastcall __noreturn *)())fassign;
  off_142125678[0] = (void (__fastcall __noreturn *)())cfltcvt;
  off_142125668[0] = (void (__fastcall __noreturn *)())forcdecpt;
  off_142125670[0] = (void (__fastcall __noreturn *)())positive;
  off_142125680 = cfltcvt_l;
  off_142125688 = fassign_l;
  off_142125690 = cropzeros_l;
  result = forcdecpt_l;
  off_142125698 = forcdecpt_l;
  return result;
}

