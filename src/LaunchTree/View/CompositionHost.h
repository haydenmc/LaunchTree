#pragma once
#include "HostWindow.h"
#include "ICompositionVisual.h"

#include <vector>
#include <windef.h>
#include <winrt/Microsoft.Graphics.Canvas.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Composition.Desktop.h>

namespace LaunchTree::View
{
    class CompositionHost
    {
    public:
        CompositionHost(HostWindow const & hostWindow);

        winrt::Windows::UI::Composition::ContainerVisual CreateRootVisual();
        void PresentRootVisual(
            winrt::Windows::UI::Composition::ContainerVisual rootVisual);

    private:
        HostWindow const & m_hostWindow;
        const winrt::Windows::System::DispatcherQueueController
            m_dispatcherQueueController{ nullptr };
        const winrt::Windows::UI::Composition::Compositor m_compositor{ nullptr };
        const winrt::Windows::UI::Composition::Desktop::DesktopWindowTarget m_target{ nullptr };
        // Win2D
        const winrt::Microsoft::Graphics::Canvas::CanvasDevice m_canvasDevice{ nullptr };
        const winrt::Windows::UI::Composition::CompositionGraphicsDevice
            m_graphicsDevice{ nullptr };

        std::vector<std::unique_ptr<ICompositionVisual>> m_visuals;
    };
}
