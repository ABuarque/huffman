<?xml version="1.0"?>
<interface>
  <!-- interface-requires gtk+ 2.12 -->
  <!-- interface-naming-policy project-wide -->
  <object class="GtkWindow" id="popup_w">
    <property name="title" translatable="yes">ERRO !</property>
    <signal name="delete_event" handler="gtk_widget_hide_on_delete"/>
    <child>
      <object class="GtkLabel" id="label1">
        <property name="visible">True</property>
        <property name="label" translatable="yes">ENTRADA INVÁLIDA.</property>
      </object>
    </child>
  </object>
</interface>