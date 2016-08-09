sfp_trunk.h
===

Trunk是错别字，实为Thunk。

Thunk技术在Win32开发中，一般用于将类成员WndProc函数提供给WNDCLASSEX::lpfnWndProc做回调。

由于C/C++缺乏运行时的动态模板技术，所以一般使用内嵌机器码的方式实现Thunk。

我这里的实现，采用了[AsmJit](https://github.com/asmjit/asmjit)，以一种可读性更高（运行时编译汇编语言）的方式实现。

sfp_trunk.h实际上为了取代某泄漏项目《江X Online》中的相关代码所编写。原代码无法在64位系统下正确运行。

当然，这个代码还是有些小问题的，但是至少可以让项目跑起来。
