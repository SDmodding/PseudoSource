// File Line: 25
// RVA: 0xA27C90
void __fastcall UFG::UIGfxLog::LogMessageVarg(
        UFG::UIGfxLog *this,
        Scaleform::LogMessageId messageId,
        const char *fmt,
        char *argList)
{
  if ( UFG::gUIPrint )
    UFG::qStringLength(fmt);
}

