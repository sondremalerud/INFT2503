#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry entry;
    Gtk::Entry entry2;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Combine names");
        button.set_sensitive(false); // Setter knappen til "grå" som utgangspunkt
        set_title("Øving 4");
        box.pack_start(entry);  // Add the widget entry to box
        box.pack_start(entry2);  // Add the widget entry to box
        box.pack_start(button); // Add the widget button to box
        box.pack_start(label);  // Add the widget label to box

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        // Gjør knapp tilgjengelig dersom det er tekst i begge input-feltene, grå ellers
        entry.signal_changed().connect([this]() {
            button.set_sensitive(!entry.get_text().empty() && !entry2.get_text().empty());
        });

        entry2.signal_changed().connect([this]() {
            button.set_sensitive(!entry.get_text().empty() && !entry2.get_text().empty());
        });

        entry.signal_activate().connect([this]() {
            label.set_text("Entry activated");
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Names combined: " + entry.get_text() + " " + entry2.get_text());
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
