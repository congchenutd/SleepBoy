#include "SleepItemEditorFactory.h"
#include "SleepItemEditor.h"

QWidget* SleepItemEditorFactory::createEditor(int userType, QWidget* parent) const
{
    return new SleepItemEditor(parent);
}
