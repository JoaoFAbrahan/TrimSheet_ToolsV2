#ifndef ISTARTCOMPONENT_H
#define ISTARTCOMPONENT_H

namespace Controller {
class IStartComponent {
public:
    virtual void StartStyleTheme() = 0;
    virtual void StartIcons() = 0;
    virtual void StartLabels() = 0;
};
}

#endif // ISTARTCOMPONENT_H
