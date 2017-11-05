<?xml version="1.0"?>
<interface>
  <!-- interface-requires gtk+ 2.12 -->
  <!-- interface-naming-policy project-wide -->
  <object class="GtkWindow" id="main_w">
    <signal name="destroy" handler="gtk_main_quit"/>
    <child>
      <object class="GtkButton" id="button1">
        <property name="label" translatable="yes">gtk-preferences</property>
        <property name="visible">True</property>
        <property name="can_focus">True</property>
        <property name="receives_default">True</property>
        <property name="use_stock">True</property>
        <signal name="clicked" handler="cb_show_prop"/>
      </object>
    </child>
  </object>
  <object class="GtkWindow" id="popup_w">
    <property name="title" translatable="yes">Properties</property>
    <signal name="delete_event" handler="gtk_widget_hide_on_delete"/>
    <child>
      <object class="GtkLabel" id="label1">
        <property name="visible">True</property>
        <property name="label" translatable="yes">This pop-up is safe.</property>
      </object>
    </child>
  </object>
</interface>